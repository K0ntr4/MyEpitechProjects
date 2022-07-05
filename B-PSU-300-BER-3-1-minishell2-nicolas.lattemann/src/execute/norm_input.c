/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include "minishell.h"

void check_char(char *input, int arg, char *str, int *n)
{
    if (input[n[0]] == 9 && arg == 0)
        input[n[0]] = ' ';
    if (input[n[0]] == '"' && arg == 0)
        arg = 1;
    else if (input[n[0]] == '"' && arg == 1)
        arg = 0;
    if (input[n[0]] == ' ' && str[n[0] - (1 + n[1])] == ' ' && arg == 0)
        n[1] += 1;
    else
        str[n[0] - n[1]] = input[n[0]];
}

char *norm_user_input(char *input)
{
    char *str = malloc(sizeof(char) * my_strlen(input));;
    int n[2] = {0, 0};
    int arg = 0;

    if (input[my_strlen(input) - 1] == '\n')
        input[my_strlen(input) - 1] = '\0';
    else
        my_putchar('\n');
    for (; input[n[0]]; n[0] += 1) {
        check_char(input, arg, str, n);
    }
    str[n[0] - n[1]] = '\0';
    free(input);
    return str;
}
