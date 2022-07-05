/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "header.h"
#include "parser.h"

static int is_valid(int n, char **params)
{
    int cond1 = n != 4;
    int cond2 = !params[1] || my_strlen(params[1]) < 2;

    return cond1 || cond2;
}

int main(int argc, char **argv)
{
    char *result = NULL;
    char *expression = NULL;
    size_t exp_len = 0;

    if (argc > 1 && my_strcmp(argv[1], "-h") == 0)
        return help();
    if (!argv[2] || my_strlen(argv[2]) != 7)
        syntax_exit();
    if (is_valid(argc, argv))
        return help_short(argv[0]);
    exp_len = my_getnbr(argv[3]);
    expression = malloc(sizeof(char) * (exp_len + 1));
    read(0, expression, exp_len);
    expression[exp_len] = '\0';
    result = bistromatic(argv, expression);
    my_putstr(result);
    my_putchar('\n');
    free(result);
    return 0;
}
