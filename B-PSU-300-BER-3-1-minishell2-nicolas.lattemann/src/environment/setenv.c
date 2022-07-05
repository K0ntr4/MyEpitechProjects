/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <stddef.h>
#include <minishell.h>
#include <malloc.h>
#include "my.h"

char *get_env_var(char *name, list_t *env)
{
    env_var_t *var = NULL;

    to_start(&env);
    while (env) {
        var = env->item;
        if (my_strcmp(var->name, name) == 0) {
            return var->value;
        }
        env = env->next;
    }
    return NULL;
}

list_t *find_env_var(char *name, list_t *env)
{
    char *item = NULL;

    to_start(&env);
    while (env) {
        item = ((env_var_t *) env->item)->name;
        if (my_strcmp(item, name) == 0) {
            return env;
        }
        env = env->next;
    }
    return NULL;
}

int is_env_var(char *str)
{
    int i = 0;
    int j = 0;
    int eq = 0;

    for (; str[i] && str[i] != '='; i++);
    if (str[i] == '=')
        eq = 1;
    for (; str[i + j]; j++);
    return i && j && eq;
}

env_var_t *prepare_set(char *str)
{
    int i = 0;
    int j = 0;
    env_var_t *var = malloc(sizeof(env_var_t));

    for (; str[i] && str[i] != '='; i++);
    for (; str[1 + i + j]; j++);
    var->name = malloc(sizeof(char) * (i + 1));
    var->value = malloc(sizeof(char) * (j + 1));
    for (int x = 0; x < j + 1; x++)
        var->value[x] = '\0';
    for (i = 0; str[i] && str[i] != '='; i++)
        var->name[i] = str[i];
    var->name[i++] = '\0';
    for (j = 0; str[i + j]; j++)
        var->value[j] = str[i + j];
    if (my_strlen(var->value) > 0 && var->value[j - 1] == '\n') {
        var->value[j - 1] = '\0';
    }
    return var;
}

char **env_to_char_array(list_t *env)
{
    int env_len = list_length(env);
    char **env_arr = malloc(sizeof(char *) * (env_len + 1));
    env_var_t *var = 0;
    char *env_var = NULL;

    to_start(&env);
    for (int i = 0; i < env_len && env; i++) {
        var = env->item;
        env_var = my_strjoin(var->name, "=", 0);
        env_arr[i] = my_strjoin(env_var, var->value, 0);
        free(env_var);
        env = env->next;
    }
    env_arr[env_len] = NULL;
    return env_arr;
}
