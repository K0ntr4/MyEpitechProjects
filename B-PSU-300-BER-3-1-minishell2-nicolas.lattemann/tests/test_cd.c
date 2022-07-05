/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include <criterion/criterion.h>
#include <minishell.h>

list_t *gen_env(void)
{
    list_t *env = NULL;
    env_var_t *env_var1 = prepare_set("PWD=/dev");
    env_var_t *env_var2 = prepare_set("USER=nlattemann");
    env_var_t *env_var3 = prepare_set("QT_IM_MODULE=xim");
    env_var_t *env_var4 = prepare_set("HOME=/boot");

    append_item(&env, env_var1);
    append_item(&env, env_var2);
    append_item(&env, env_var3);
    append_item(&env, env_var4);
    return env;
}

Test(cd, 1)
{
    list_t *env = gen_env();

    my_cd(&env, my_strdup("cd ~"));
    cr_expect_str_eq(get_env_var("PWD", env), "/boot");
}

Test(cd, 2)
{
    list_t *env = gen_env();

    my_cd(&env, my_strdup("cd /dev"));
    cr_expect_str_eq(get_env_var("PWD", env), "/dev");
}

Test(cd, 3)
{
    list_t *env = gen_env();

    cr_expect_eq(my_cd(&env, "cd banana"), 84);
}
