/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <stddef.h>
#include "my.h"
#include "minishell.h"

char is_cd(char *command)
{
    int cond1 = my_strncmp(command, "cd ", 3) == 0;
    int cond2 = my_strcmp(command, "cd\0") == 0;

    return cond1 || cond2;
}

char *cd_get_path(list_t **env, char *command)
{
    char *path = &command[3];

    if (my_strcmp(path, ".") == 0)
        return NULL;
    if (my_strcmp(path, "~") == 0 || !my_strlen(path))
        path = get_env_var("HOME", *env);
    if (my_strcmp(path, "-") == 0)
        path = get_env_var("OLDPWD", *env);
    if (path == NULL || !my_strlen(path)) {
        my_puterror(": No such file or directory.\n");
        return NULL;
    }
    return path;
}
