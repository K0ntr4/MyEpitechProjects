/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include "minishell.h"

int execute_rebuilds(command_t *command, list_t **env)
{
    env_var_t *new_env_var = NULL;

    if (!my_strcmp(command->command, EXIT_CMD)) {
        free(command);
        return 2;
    }
    if (un_setenv(command->command, env))
        return 1;
    if (is_cd(command->command)) {
        my_cd(env, command->command);
        return 1;
    }
    if (is_env_var(command->command)) {
        new_env_var = prepare_set(command->command);
        my_setenv(new_env_var->name, new_env_var->value, *env);
        free(new_env_var);
        return 1;
    }
    return 0;
}

int update_string(char c, int string)
{
    if (c == '"' && string == 0)
        return 1;
    if (c == '"' && string == 1)
        return 0;
    return string;
}
