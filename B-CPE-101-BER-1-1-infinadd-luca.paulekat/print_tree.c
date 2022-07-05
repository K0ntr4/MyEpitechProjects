/*
** EPITECH PROJECT, 2021
** btree_apply_prefix
** File description:
** applies
*/
#include "include/my.h"

void print_tree(btree_t *root , void (*applyf)(char))
{
    if (root == NULL)
        return;
    applyf(root->item);
    if (root->left != NULL)
        print_tree(root->left, applyf);
    free(root);
}
