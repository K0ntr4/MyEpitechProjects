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

int verify(char *expr, int i)
{
    switch (expr[i]) {
    case ')': return closing_parentheses(expr, i);
    case '(': return opening_parentheses(expr, i);
    case '+': return dashes(expr, i);
    case '-': return dashes(expr, i);
    case '*': return dots(expr, i);
    case '/': return dots(expr, i);
    case '%': return dots(expr, i);
    }
    return 0;
}

int validate_subprocess(char *expression, int i)
{
    while (expression[i] != '#') {
        verify(expression, i);
        if (expression[i] == '(') {
            i++;
            i = validate_subprocess(expression, i);
            continue;
        }
        if (expression[i] == ')') {
            i++;
            return i;
        }
        i++;
    }
    syntax_exit();
    return 84;
}

int validate(char *expression, int i)
{
    while (expression[i] != '#') {
        verify(expression, i);
        if (expression[i] == '(') {
            i++;
            i = validate_subprocess(expression, i);
            continue;
        }
        if (expression[i] == ')') {
            i++;
            return i;
        }
        i++;
    }
    return i;
}

int validate_expression(char *expression)
{
    int valid = validate(expression, 0);

    if (!valid)
        syntax_exit();
    return valid;
}
