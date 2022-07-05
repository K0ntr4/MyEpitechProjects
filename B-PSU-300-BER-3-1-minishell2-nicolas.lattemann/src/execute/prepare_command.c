/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <malloc.h>
#include <minishell.h>
#include "my.h"

void to_next_sign(char *cmd, int *i, int len)
{
    while (!includes("|><", cmd[*i]) && *i < len) {
        *i = *i + 1;
    }
}

char *get_dest(char *cmd, int *i, int len)
{
    int start = 0;
    int end = 0;
    char *copy = NULL;
    char sign = 0;

    for (; includes("\t ", cmd[*i]); *i = *i + 1);
    switch (cmd[*i]) {
        case '|': return my_strdup("0");
        case '>':sign = '3';
            if (cmd[(*i) + 1] == '>') {
                *i = *i + 1;
                sign = '4';
            }
            start = get_start(cmd, *i);
            *i = start;
            for (; !to_skip(cmd[*i]) && *i < len; *i = *i + 1);
            end = get_end(cmd, *i);
            *i = end;
            copy = partial_copy(cmd, start - 1, end);
            copy[0] = sign;
            return copy;
        default: return my_strdup("1");
    }
}

char *get_in(char *cmd, int *i, int len)
{
    int start = 0;
    int end = 0;
    char *copy = NULL;
    char sign = 0;

    for (; includes("\t ", cmd[*i]); *i = *i + 1);
    switch (cmd[*i]) {
        case '<': sign = '3';
            if (cmd[(*i) + 1] == '<') {
                *i = *i + 1;
                sign = '4';
            }
            start = get_start(cmd, *i);
            *i = start;
            for (; !to_skip(cmd[*i]) && *i < len; *i = *i + 1);
            end = get_end(cmd, *i);
            *i = end;
            copy = partial_copy(cmd, start - 1, end);
            copy[0] = sign;
            return copy;
        default: return my_strdup("0");
    }
}

list_t *to_list(char *cmd)
{
    int len = my_strlen(cmd);
    int start = 0;
    int end = 0;
    char *copy = NULL;
    command_t *subcommand = NULL;
    list_t *command_chain = NULL;

    for (int i = 0; i < len; i++) {
        start = get_start(cmd, i);
        to_next_sign(cmd, &i, len);
        end = get_end(cmd, i);
        copy = partial_copy(cmd, start, end);
        subcommand = malloc(sizeof(command_t));
        subcommand->command = copy;
        subcommand->in = get_in(cmd, &i, len);
        subcommand->dest = get_dest(cmd, &i, len);
        append_item(&command_chain, subcommand);
    }
    return command_chain;
}

list_t *parse_command(char *cmd)
{
    list_t *cmd_chain = NULL;
    list_t *subcommand_list = NULL;
    int start = 0;
    int end = 0;
    int found = 0;

    for (int i = 0; i < my_strlen(cmd); i++) {
        if (!includes("\t; ", cmd[i]))
            found = 1;
        if (found && (cmd[i] == ';' || (my_strlen(cmd) - 1) == i)) {
            start = get_start(cmd, start);
            end = get_end(cmd, i);
            if (cmd[i] == ';' && cmd[i + 1] == ';') {
                continue;
            }
            subcommand_list = to_list(partial_copy(cmd, start, end));
            if (subcommand_list == NULL) {
                return NULL;
            }
            append_item(&cmd_chain, subcommand_list);
            start = i + 1;
        }
    }
    return cmd_chain;
}
