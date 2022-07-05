/*
** EPITECH PROJECT, 2021
** btree_apply_suffix
** File description:
** applies function post order
*/
#include "include/my.h"

void free_tree(btree_t *root)
{
    if (root == NULL)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
