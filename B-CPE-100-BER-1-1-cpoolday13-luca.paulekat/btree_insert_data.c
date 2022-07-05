/*
** EPITECH PROJECT, 2021
** btree_apply_suffix
** File description:
** applies function post order
*/
#include "include/btree.h"

void insert_elem_in_tree(btree_t *root, void *item, int (*cmpf)())
{
    if (root->right == NULL) {
        root->right = btree_create_node(item);
        return;
    } else if (root->left == NULL) {
        root->left = btree_create_node(item);
        return;
    }
    if (cmpf(root->item, item) > 0)
        insert_elem_in_tree(root->left, item, cmpf);
    else if (cmpf(root->item, item) <= 0)
        insert_elem_in_tree(root->right, item, cmpf);
}

void btree_insert_data(btree_t **root , void *item , int (*cmpf)())
{
    if (root == NULL) {
        *root = btree_create_node(item);
        return;
    }
    insert_elem_in_tree(*root, item, cmpf);
}
