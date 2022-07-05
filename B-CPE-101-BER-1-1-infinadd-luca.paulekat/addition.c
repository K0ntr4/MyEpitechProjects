/*
** EPITECH PROJECT, 2021
** addition
** File description:
** performs addition for infinite add
*/
#include "include/my.h"

void overflow(btree_t *tree)
{
    if (tree == NULL) {
        return;
    }
    tree->item += 1;
    if (tree->item >= 58) {
        tree->item -= 10;
        overflow(tree->right);
    }
}

btree_t **add_together(int n, char **nb)
{
    int l = my_strlen(nb[1]);
    int res[3] = {0, 0, 0};
    char r;
    btree_t *tree = malloc(sizeof(btree_t));
    btree_t **start = &tree->left;

    for (int i = 0; i < l; i++) {
        res[0] = nb[1][i] - 48;
        res[1] = nb[2][i] - 48;
        res[2] = res[0] + res[1];
        if (res[2] >= 10) {
            res[2] -= 10;
            overflow(tree);
        }
        r = res[2] + 48;
        tree->left = btree_create_node(r);
        tree->left->right = tree;
        tree = tree->left;
    }
    return (start);
}
