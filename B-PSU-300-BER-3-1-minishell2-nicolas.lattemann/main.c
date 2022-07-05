/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <stddef.h>
#include "my.h"
#include "minishell.h"

int main(int argc, char **argv, char **env)
{
    list_t *env_variables = NULL;
    list_t *next = NULL;

    argc = argc;
    argv = argv;
    for (int i = 0; env[i]; i++) {
        append_item(&env_variables, prepare_set(env[i]));
    }
    my_unsetenv("OLDPWD", env_variables);
    minishell(&env_variables);
    to_start(&env_variables);
    while (env_variables) {
        next = env_variables->next;
        free(((command_t *) env_variables->item)->command);
        free(((command_t *) env_variables->item)->dest);
        free(env_variables->item);
        free(env_variables);
        env_variables = next;
    }
    return 0;
}
