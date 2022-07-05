/*
** EPITECH PROJECT, 2021
** btree_apply_infix
** File description:
** applies function in order
*/
#include "include/btree.h"

void btree_apply_infix(btree_t *root , int (* applyf)(void *))
{
    if (root == NULL)
        return;
    btree_apply_infix(root->left, applyf);
    applyf(root->item);
    btree_apply_infix(root->right, applyf);
}
