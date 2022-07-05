/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <minishell.h>
#include "my.h"

void printenv(list_t *env)
{
    to_start(&env);
    while (env) {
        my_putstr(((env_var_t *) env->item)->name);
        my_putchar('=');
        my_putstr(((env_var_t *) env->item)->value);
        my_putchar('\n');
        env = env->next;
    }
}

list_t *my_setenv(char *name, char *value, list_t *env)
{
    env_var_t *var = NULL;
    list_t *var_env = find_env_var(name, env);

    if (var_env == NULL) {
        var = malloc(sizeof(env_var_t));
        var->name = name;
        var->value = value;
        append_item(&env, var);
    } else {
        if (((env_var_t *) var_env->item)->value)
            free(((env_var_t *) var_env->item)->value);
        ((env_var_t *) var_env->item)->value = value;
    }
    return env;
}

list_t *my_unsetenv(char *name, list_t *env)
{
    list_t *var_env = find_env_var(name, env);

    if (var_env) {
        if (((env_var_t *) var_env->item)->name != NULL)
            free(((env_var_t *) var_env->item)->name);
        if (((env_var_t *) var_env->item)->value != NULL)
            free(((env_var_t *) var_env->item)->value);
        delete_item(&var_env);
    }
    return env;
}

int is_unsetenv(char *cmd)
{
    int cond1 = my_strcmp(cmd, "unsetenv") == 0;
    int cond2 = my_strcmp(cmd, "setenv") == 0;

    return cond1 || cond2;
}

int un_setenv(char *cmd, list_t **env)
{
    char **args = split_args(cmd, ' ');
    int arr_len = arr_length(args);

    to_start(env);
    if (!is_unsetenv(args[0]))
        return 0;
    if (my_strcmp(args[0], "unsetenv") == 0) {
        if (arr_len < 2)
            my_puterror("unsetenv: Too few arguments.\n");
        for (int i = 1; i < arr_len; i++) {
            to_start(env);
            *env = my_unsetenv(args[i], *env);
        }
    }
    if (my_strcmp(args[0], "setenv") == 0) {
        if (arr_len > 3)
            my_puterror("setenv: Too many arguments.\n");
        if (arr_len == 1)
            return 0;
        if (arr_len == 3)
            my_setenv(args[1], arr_len < 3 ? my_strdup("") : args[2], *env);
    }
    return 1;
}
