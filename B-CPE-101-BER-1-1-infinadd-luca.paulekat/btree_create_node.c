/*
** EPITECH PROJECT, 2021
** btree_create_node
** File description:
** creates a node
*/
#include "include/my.h"

btree_t *btree_create_node(char c)
{
    btree_t *new_node = malloc(sizeof(btree_t));

    new_node->item = c;
    new_node->right = NULL;
    new_node->left = NULL;
    return (new_node);
}
