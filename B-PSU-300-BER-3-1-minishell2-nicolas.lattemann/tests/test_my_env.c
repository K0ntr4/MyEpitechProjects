/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include <criterion/criterion.h>
#include "minishell.h"

Test(real_my_env, unforced)
{
    list_t *env = NULL;
    list_t *new_env = NULL;
    env_var_t *env_var1 = prepare_set("DESKTOP_SESSION=plasmax11");
    env_var_t *env_var2 = prepare_set("USER=nlattemann");
    env_var_t *env_var3 = prepare_set("QT_IM_MODULE=xim");
    env_var_t *env_var4 = prepare_set("HISTCONTROL=ignoredups");

    append_item(&env, env_var1);
    append_item(&env, env_var2);
    append_item(&env, env_var3);
    append_item(&env, env_var4);
    new_env = real_my_env(env);
    my_unsetenv("DESKTOP_SESSION", new_env);
    to_start(&new_env);
    to_start(&env);
    cr_expect_str_eq(env_var1->name, (char *)((env_var_t *)env->item)->name);
    cr_expect_str_eq(env_var2->name, (char *)((env_var_t *)new_env->item)
    ->name);
}

Test(my_env, 1)
{
    list_t *env = NULL;
    env_var_t *env_var1 = prepare_set("DESKTOP_SESSION=plasmax11");
    env_var_t *env_var2 = prepare_set("USER=nlattemann");
    env_var_t *env_var3 = prepare_set("QT_IM_MODULE=xim");
    env_var_t *env_var4 = prepare_set("HISTCONTROL=ignoredups");

    append_item(&env, env_var1);
    append_item(&env, env_var2);
    append_item(&env, env_var3);
    append_item(&env, env_var4);
    cr_expect_eq(my_env(env), 0);
}
