/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include "header.h"
#include "my.h"
#include "parser.h"

#include <stddef.h>

char *eval_expr(char *expr, int base)
{
    ast_t *root = parse_expression(expr, base);
    char *result = NULL;

    eval_tree(root);
    result = my_strdup(root->item);
    free_ast(root);
    return result;
}
