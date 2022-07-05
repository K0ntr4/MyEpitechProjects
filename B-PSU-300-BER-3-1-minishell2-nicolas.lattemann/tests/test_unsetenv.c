/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include <criterion/criterion.h>
#include "minishell.h"

Test(unsetenv, exist)
{
    list_t *env = NULL;
    env_var_t *env_var1 = prepare_set("DESKTOP_SESSION=plasmax11");
    env_var_t *env_var2 = prepare_set("USER=nlattemann");
    env_var_t *env_var3 = prepare_set("QT_IM_MODULE=xim");
    env_var_t *env_var4 = prepare_set("HISTCONTROL=ignoredups");
    env_var_t *current = NULL;

    append_item(&env, env_var1);
    append_item(&env, env_var2);
    append_item(&env, env_var3);
    append_item(&env, env_var4);
    my_unsetenv("USER", env);
    to_start(&env);
    current = ((env_var_t *) env->item);
    cr_expect_str_eq(env_var1->name, current->name);
    cr_expect_str_eq(env_var1->value, current->value);
    env = env->next;
    current = ((env_var_t *) env->item);
    cr_expect_str_eq(env_var3->name, current->name);
    cr_expect_str_eq(env_var3->value, current->value);
    env = env->next;
    current = ((env_var_t *) env->item);
    cr_expect_str_eq(env_var4->name, current->name);
    cr_expect_str_eq(env_var4->value, current->value);
}

Test(unsetenv, doesnt_exist)
{
    list_t *env = NULL;
    env_var_t *env_var1 = prepare_set("DESKTOP_SESSION=plasmax11");
    env_var_t *env_var2 = prepare_set("USER=nlattemann");
    env_var_t *env_var3 = prepare_set("QT_IM_MODULE=xim");
    env_var_t *env_var4 = prepare_set("HISTCONTROL=ignoredups");
    env_var_t *current = NULL;

    append_item(&env, env_var1);
    append_item(&env, env_var2);
    append_item(&env, env_var3);
    append_item(&env, env_var4);
    my_unsetenv("COUNTRY", env);
    to_start(&env);
    current = ((env_var_t *)env->item);
    cr_expect_str_eq(env_var1->name, current->name);
    cr_expect_str_eq(env_var1->value, current->value);
    env = env->next;
    current = ((env_var_t *)env->item);
    cr_expect_str_eq(env_var2->name, current->name);
    cr_expect_str_eq(env_var2->value, current->value);
    env = env->next;
    current = ((env_var_t *)env->item);
    cr_expect_str_eq(env_var3->name, current->name);
    cr_expect_str_eq(env_var3->value, current->value);
    env = env->next;
    current = ((env_var_t *)env->item);
    cr_expect_str_eq(env_var4->name, current->name);
    cr_expect_str_eq(env_var4->value, current->value);
}
