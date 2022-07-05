/*
** EPITECH PROJECT, 2021
** btree_search_item
** File description:
** searches item
*/
#include "include/btree.h"

void *btree_search_item(btree_t const *root, void const *data_ref, \
int (*cmpf)())
{
    void *p = NULL;

    if (root == NULL) {
        return;
    }
    if (cmpf(root->item, data_ref) == 0) {
        p = root;
        return (p);
    } else {
        btree_search_item(root->left, data_ref, cmpf);
        btree_search_item(root->right, data_ref, cmpf);
    }
    return (p);
}
