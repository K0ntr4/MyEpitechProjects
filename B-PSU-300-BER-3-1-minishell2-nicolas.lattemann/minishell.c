/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <unistd.h>
#include <minishell.h>
#include <stdio.h>
#include "my.h"

char *get_folder_name(list_t **env)
{
    char *pwd = get_env_var("PWD", *env);
    int last_slash = 0;

    if (!pwd)
        pwd = get_env_var("OLDPWD", *env);
    if (!pwd)
        return my_strdup("");
    if (my_strcmp(pwd, "/") == 0)
        return my_strdup(pwd);
    for (int i = 0; pwd[i]; i++) {
        if (pwd[i] == '/')
            last_slash = i;
    }
    return my_strdup(&(pwd[last_slash + 1]));
}

int display_interface(list_t **env)
{
    char *folder_name = get_folder_name(env);
    char *user_name = get_env_var("USER", *env);

    my_putstr(user_name ? user_name : "you");
    my_putstr(" at ");
    my_putstr(folder_name ? folder_name : "unknown");
    my_putchar('\n');
    my_putstr(">> ");
    if (folder_name)
        free(folder_name);
    return 0;
}

int minishell(list_t **env)
{
    char *user_input = NULL;
    size_t len = 0;
    list_t *command_chain = NULL;
    size_t buf_size = 0;

    while (1) {
        user_input = NULL;
        display_interface(env);
        len = getline(&user_input, &buf_size, stdin);
        if (len == (long unsigned int) -1)
            exit(0);
        if (!my_strlen((user_input = norm_user_input(user_input))))
            continue;
        if (!(command_chain = parse_command(user_input)))
            continue;
        if (execute_command_chain(command_chain, env) == 2)
            break;
        free(user_input);
    }
    return 0;
}
