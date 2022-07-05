/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include "minishell.h"

char *partial_copy(const char *string, int start, int end)
{
    char *substring = malloc(sizeof(char) * (end - start + 1));
    int i = start;
    for (; i < end; i++) {
        substring[i - start] = string[i];
    }
    substring[i - start] = '\0';
    return substring;
}

int to_skip(char c)
{
    return c == '\t' || c == ' ' || includes(";<>|", c);
}

int get_start(const char *command, int start)
{
    for (; to_skip(command[start]); start++);
    return start;
}

int get_end(const char *command, int end)
{
    for (; to_skip(command[end]); end--);
    return end + 1;
}

int is_ambiguous_redirect(char c, char last_sign)
{
    if ((c == '|' || c == '>') && last_sign == '>') {
        my_puterror("Ambiguous output redirect\n");
        return 1;
    }
    return 0;
}
