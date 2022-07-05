/*
** EPITECH PROJECT, 2021
** btree_create_node
** File description:
** creates a node
*/
#include "include/btree.h"

btree_t *btree_create_node(void *item)
{
    btree_t *new_node = malloc(sizeof(btree_t));

    new_node->item = item;
    new_node->right = NULL;
    new_node->left = NULL;
    return (new_node);
}
