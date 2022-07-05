/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include <stddef.h>
#include <stdlib.h>

#include "header.h"
#include "my.h"

short is_num(char c)
{
    return 48 <= c && c <= 57;
}

char *resize(char *str, int n)
{
    char *new_str = malloc(sizeof(char) * (n + 1));

    for (int i = 0; i < n; i++)
        new_str[i] = str[i];
    new_str[n] = '\0';
    free(str);
    return new_str;
}

char *prep_expression(char *str)
{
    char *new_str = malloc(sizeof(char) * (my_strlen(str) + 2));

    new_str[0] = '#';
    new_str[1] = '\0';
    my_strcat(new_str, str);
    return new_str;
}

int is_par(char *expr)
{
    int cond1 = includes("()", expr[0]);
    int cond2 = 0;
    int cond3 = includes("%*/+-#(", expr[-1]);
    int i = 0;

    for (; expr[0] == '-' && expr[i] != '('; i++) {
        if (!includes("+-", expr[i]))
            break;
    }
    if (expr[i] == '(')
        cond2 = 1;
    if (cond1 || (cond2 && cond3))
        return cond1 ? -1 : i;
    return 0;
}

int is_neg_par(char *expr)
{
    int cond1 = 0;
    int cond2 = includes("%*/+-#(", expr[-1]);
    int cond3 = 0;
    int is_neg = 0;
    int i = -2;

    for (i = 0; expr[0] == '-' && expr[i] != '('; i++) {
        if (!includes("+-", expr[i]))
            break;
        is_neg += expr[i] == '-' ? 1 : 0;
    }
    if (expr[i] == '(')
        cond1 = 1;
    cond3 = is_neg % 2 ? 1 : 0;
    return cond1 && cond2 && cond3;
}
