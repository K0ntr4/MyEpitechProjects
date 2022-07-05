/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <stddef.h>
#include "my.h"
#include "minishell.h"

static list_t *reverse_list(list_t *list)
{
    list_t *reversed_list = NULL;

    while (list) {
        append_item(&reversed_list, pop(&list));
    }
    free_list(list);
    return reversed_list;
}

list_t *fragment_path(char *path)
{
    char *path_copy = NULL;
    list_t *fragmented_path = NULL;
    int ind = 0;

    if (!path)
        return NULL;
    path_copy = my_strdup(path);
    for (int i = my_strlen(path_copy); i >= 0; i--) {
        if (path_copy[i] == '/' || i == 0) {
            ind = i == 0 && path_copy[i] != '/' ? i : i + 1;
            if (my_strlen(&path_copy[ind]) > 0)
                append_item(&fragmented_path, my_strdup(&path_copy[ind]));
            if (i == 0 && path_copy[i] == '/')
                append_item(&fragmented_path, my_strdup("/"));
            path_copy[i] = '\0';
        }
    }
    free(path_copy);
    return reverse_list(fragmented_path);
}

char *join_path(list_t *list)
{
    char *path = my_strdup("");
    char *item = NULL;

    to_start(&list);
    while (list) {
        item = list->item;
        if (item)
            path = my_strjoin(path, item, 1);
        list = list->next;
        if (list && (my_strcmp(path, "/") != 0))
            path = my_strjoin(path, my_strdup("/"), 1);
    }
    return path;
}

char *recon_abs_path(char *path)
{
    list_t *absolute_path = fragment_path(getcwd(NULL, 0));
    char *str = NULL;
    list_t *fragmented_path = fragment_path(path);

    if (!absolute_path) {
        return NULL;
    }
    to_start(&fragmented_path);
    while (fragmented_path) {
        str = (char *) fragmented_path->item;
        if (my_strcmp(str, "..\0") == 0)
            pop(&absolute_path);
        else
            append_item(&absolute_path, my_strdup(str));
        fragmented_path = fragmented_path->next;
    }
    free_list(fragmented_path);
    return join_path(absolute_path);
}

int my_cd(list_t **env, char *command)
{
    char *path = cd_get_path(env, command);
    char *new_path = NULL;
    list_t *list = find_env_var("PWD", *env);

    if (!list)
        list = find_env_var("OLDPWD", *env);
    if (path == NULL)
        return 0;
    new_path = path[0] != '/' ? recon_abs_path(path) : my_strdup(path);
    if (!new_path)
        return my_puterror("84: Failed to retrieve PWD.\n");
    if (verify_directory(new_path, path) == 84)
        return 84;
    my_setenv("OLDPWD", my_strdup(((env_var_t *) list->item)->value), *env);
    free(((env_var_t *) list->item)->value);
    ((env_var_t *) list->item)->value = my_strdup(new_path);
    chdir(new_path);
    free(new_path);
    return 0;
}
