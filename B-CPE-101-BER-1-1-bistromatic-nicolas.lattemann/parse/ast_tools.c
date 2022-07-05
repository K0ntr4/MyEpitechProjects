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

ast_t *new_ast_node(char *item, ast_t *left, ast_t *right)
{
    ast_t *ast_node = malloc(sizeof(ast_t));

    ast_node->item = item;
    ast_node->left = left;
    ast_node->right = right;
    return ast_node;
}

int print_ast(ast_t *root, int level)
{
    if (root == NULL)
        return 0;
    for (int i = 0; i < level; i++)
        my_putstr(i == level - 1 ? "|- " : "  ");
    my_putstr(root->item);
    my_putchar('\n');
    print_ast(root->left, level + 1);
    print_ast(root->right, level + 1);
    return 0;
}

void  add_node(list_t **ast_stack, char *oper)
{
    ast_t *ast_node = new_ast_node(oper, pop(ast_stack), pop(ast_stack));

    append_item(ast_stack, ast_node);
}

int free_ast(ast_t *node)
{
    if (!node)
        return 0;
    free_ast(node->left);
    free_ast(node->right);
    free(node->item);
    free(node);
    return 0;
}
