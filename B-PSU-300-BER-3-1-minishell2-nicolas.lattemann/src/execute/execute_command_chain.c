/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <minishell.h>
#include <stdio.h>
#include <fcntl.h>
#include "my.h"

void open_out_pipe(command_t *cmd)
{
    int rights = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int mode = cmd->dest[0] == '3' ? CREATE : APPEND;

    if (!((my_strlen(cmd->dest) == 1) && ('1' == cmd->dest[0]))) {
        dup2(open(&cmd->dest[1], mode, rights), STDOUT_FILENO);
    }
}

void recover_pipe(int stdout_bk, int stdin_bk)
{
    dup2(stdout_bk, STDOUT_FILENO);
    dup2(stdin_bk, STDIN_FILENO);
}

void pip_input(command_t *cmd)
{
    int fd = 0;

    if (!((my_strlen(cmd->in) == 1) && ('0' == cmd->in[0]))) {
        if (my_strlen(cmd->in) == 1 && includes("012", cmd->in[0])) {
            fd = cmd->in[0] - 48;
        } else {
            fd = open(&cmd->in[1], O_RDONLY);
        }
        dup2(fd, STDIN_FILENO);
    }
}

int execute_subcommand_chain(list_t *subcmd_chain, list_t **env)
{
    char **new_env = env_to_char_array(*env);
    command_t *command = NULL;
    int stdout_bk = dup(STDOUT_FILENO);
    int stdin_bk = dup(STDIN_FILENO);

    while (subcmd_chain) {
        command = subcmd_chain->item;
        subcmd_chain = subcmd_chain->next;
        switch (execute_rebuilds(command, env)) {
            case 1: continue;
            case 2: return 2;
        }
        open_out_pipe(command);
        pip_input(command);
        execute_command(command->command, new_env);
        recover_pipe(stdout_bk, stdin_bk);
    }
    return 0;
}

int execute_command_chain(list_t *cmd_chain, list_t **env)
{
    list_t *subcmd_chain = NULL;
    int ret_val = 0;

    while (cmd_chain) {
        subcmd_chain = cmd_chain->item;
        to_start(&subcmd_chain);
        ret_val = execute_subcommand_chain(subcmd_chain, env);
        if (ret_val == 2)
            return ret_val;
        cmd_chain = cmd_chain->next;
    }
    return 0;
}
