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

static int is_num_node(ast_t *str)
{
    char *num = NULL;

    if (!str)
        return 0;
    num = str->item;
    if (is_num(num[0]))
        return 1;
    if (num[0] == '-' && is_num(num[1]))
        return 1;
    return 0;
}

static char *calculate(ast_t *node)
{
    char *num1 = node->left->item;
    char *num2 = node->right->item;

    switch (node->item[0]) {
    case '*':
        return infinmul(num1, num2);
    case '+':
        return infinadd(num1, num2);
    case '-':
        return infinsub(num1, num2);
    case '/':
        return infindiv(num1, num2);
    case '%':
        return infinmod(num1, num2);
    default:
        my_putstr("invalid operand");
        exit(84);
    }
    return 0;
}

static int to_be_processed(ast_t *node)
{
    int cond1 = includes(OPER, node->item[0]) && node->item[1] == '\0';
    int cond2 = is_num_node(node->left) && is_num_node(node->right);

    return cond1 && cond2;
}

static void evaluate(ast_t *node)
{
    char *result = NULL;

    if (!node)
        return;
    evaluate(node->left);
    if (to_be_processed(node)) {
        result = calculate(node);
        free(node->item);
        node->item = result;
    }
    evaluate(node->right);
}

void eval_tree(ast_t *node)
{
    while (!is_num_node(node)) {
        evaluate(node);
    }
}
