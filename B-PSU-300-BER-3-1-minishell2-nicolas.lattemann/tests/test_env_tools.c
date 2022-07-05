/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include <criterion/criterion.h>
#include <minishell.h>

Test(env_to_char_array, 1)
{
    list_t *env = NULL;
    char **env_array = NULL;
    env_var_t *env_var1 = prepare_set("DESKTOP_SESSION=plasmax11");
    env_var_t *env_var2 = prepare_set("USER=nlattemann");
    env_var_t *env_var3 = prepare_set("QT_IM_MODULE=xim");
    env_var_t *env_var4 = prepare_set("HISTCONTROL=ignoredups");

    append_item(&env, env_var1);
    append_item(&env, env_var2);
    append_item(&env, env_var3);
    append_item(&env, env_var4);
    env_array = env_to_char_array(env);
    cr_expect_str_eq(env_array[0], "DESKTOP_SESSION=plasmax11");
    cr_expect_str_eq(env_array[1], "USER=nlattemann");
    cr_expect_str_eq(env_array[2], "QT_IM_MODULE=xim");
    cr_expect_str_eq(env_array[3], "HISTCONTROL=ignoredups");
}
