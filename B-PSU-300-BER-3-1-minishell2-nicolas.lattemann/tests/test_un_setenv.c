/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include <criterion/criterion.h>
#include "minishell.h"

Test(un_setenv, unsetenv_1)
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

    un_setenv(my_strdup("unsetenv USER HISTCONTROL"), &env);
    cr_expect_eq(list_length(env), 2);
}

Test(un_setenv, setenv_1)
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
    un_setenv(my_strdup("setenv LOCAL"), &env);
    cr_expect_eq(list_length(env), 5);
}
