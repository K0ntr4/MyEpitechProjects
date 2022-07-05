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

int closing_parentheses(char *expr, int i)
{
    if (!(is_alpha_num(expr[i - 1]) || includes(")", expr[i - 1])))
        syntax_exit();
    if (!(includes(OPER, expr[i + 1]) || includes("#)", expr[i + 1])))
        syntax_exit();
    return 0;
}

int opening_parentheses(char *expr, int i)
{
    if (!(includes(OPER, expr[i - 1]) || includes("#(", expr[i - 1])))
        syntax_exit();
    if (!(is_alpha_num(expr[i + 1]) || includes("(-", expr[i + 1])))
        syntax_exit();
    return 0;
}

int dashes(char *expr, int i)
{
    if (!(is_alpha_num(expr[i - 1]) || includes("()+-*%/#", expr[i - 1])))
        syntax_exit();
    if (!(is_alpha_num(expr[i + 1]) || includes("(-+", expr[i + 1])))
        syntax_exit();
    return 0;
}

int dots(char *expr, int i)
{
    if (!(is_alpha_num(expr[i - 1]) || ')' == expr[i - 1]))
        syntax_exit();
    if (!(is_alpha_num(expr[i + 1]) || includes("(-+", expr[i + 1])))
        syntax_exit();
    return 0;
}
