/*
** EPITECH PROJECT, 2021
** btree_apply_suffix
** File description:
** applies function post order
*/
#include "include/btree.h"

void btree_apply_by_level(btree_t *root, void (* applyf)(void *item, \
int level, int is_first_elem))
{
    for (int i = 0; i < btree_level_count(root); i++)
        apply_on_lvl(root, i, applyf, 1);
}

void apply_on_lvl(btree_t *root, int lvl, void (* applyf)(void *item, \
int level, int is_first_elem), int first_elem)
{
    if (root == NULL)
        return;
    if (lvl == 1)
        applyf(root->item, lvl, first_elem);
    else if (lvl > 1) {
        apply_on_lvl(root->left, lvl - 1, applyf, 1);
        apply_on_lvl(root->right, lvl - 1, applyf, 0);
    }
}
