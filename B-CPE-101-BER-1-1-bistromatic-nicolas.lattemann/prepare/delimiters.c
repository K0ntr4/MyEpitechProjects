/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include <stdlib.h>

#include "my.h"
#include "header.h"
#include "parser.h"

char *add_delimiters(char *expression)
{
    int expr_len = my_strlen(expression);
    char *new_expression = malloc(sizeof(char) * (expr_len + 3));

    new_expression[0] = '#';
    new_expression[1] = '\0';
    my_strcat(new_expression, expression);
    new_expression[expr_len + 1] = '#';
    new_expression[expr_len + 2] = '\0';
    free(expression);
    return new_expression;
}
