/*
** EPITECH PROJECT, 2021
** btree_search_item
** File description:
** searches item
*/
#include "include/btree.h"

size_t btree_level_count(btree_t const *root)
{
    if (root == NULL)
        return (0);
    int l = btree_level_count(root->left);
    int r = btree_level_count(root->right);
    if (l > r)
        return (l + 1);
    else
        return (r + 1);
}
