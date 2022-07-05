/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include <stddef.h>
#include <stdlib.h>

#include "my.h"
#include "header.h"
#include "parser.h"

int is_alpha_num(char c)
{
    int cond1 = 48 <= c && c <= 57;
    int cond2 = 65 <= c && c <= 90;

    return cond1 || cond2;
}

void syntax_exit(void)
{
    my_putstr(SYNTAX_ERROR_MSG);
    exit(EXIT_SYNTAX);
}
