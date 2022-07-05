/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <stddef.h>
#include <minishell.h>
#include "my.h"

static list_t *copy_env(list_t *env)
{
    list_t *new_env = NULL;

    to_start(&env);
    while (env) {
        append_item(&new_env, env->item);
        env = env->next;
    }
    return new_env;
}

list_t *real_my_env(list_t *env)
{
    list_t *env_copy = copy_env(env);

    return env_copy;
}

list_t *my_env(list_t *env)
{
    free_list(real_my_env(env));
    return 0;
}
