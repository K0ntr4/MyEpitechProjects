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

char *bistromatic(char **argv, char *expression)
{
    char *result = NULL;
    char *converted_result = NULL;

    substitute(&expression, argv[1], argv[2], 1);
    expression = add_delimiters(expression);
    validate_expression(&expression[1]);
    validate_base(argv[1], argv[2]);
    result = eval_expr(&expression[1], my_strlen(argv[1]));
    converted_result = to_base(result, my_strlen(argv[1]));
    free(result);
    result = converted_result;
    substitute(&result, argv[1], argv[2], 0);
    free(expression);
    return result[0] == '-' && result[1] == '0' ? &result[1] : result;
}
