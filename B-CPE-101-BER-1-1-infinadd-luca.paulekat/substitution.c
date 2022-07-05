/*
** EPITECH PROJECT, 2021
** addition
** File description:
** performs addition for infinite add
*/
#include "include/my.h"

int sub_is_equal(char **str, int check_neg)
{
    if (my_strcmp(str[1], str[2]) == 0 && (check_neg == 2 || check_neg == 1)) {
        my_putchar('0');
        my_putchar('\n');
        return (0);
    } else {
        return (84);
    }
}

int perform_sub(char **nb, int c, int *res, btree_t *tree)
{
    if (my_strcmp(nb[1], nb[2]) < 0 && (c == 2 || c == 1)) {
        res[2] = res[1] - res[0];
        if (res[2] < 0) {
            res[2] += 10;
            overflow_neg(tree);
        }
    }
    if (my_strcmp(nb[1], nb[2]) > 0 && (c == 2 || c == 1)) {
        res[2] = res[1] - res[0];
        if (res[2] < 0) {
            res[2] *= -1;
        }
    }
    return (res[2]);
}

void overflow_neg(btree_t *tree)
{
    if (tree == NULL) {
        return;
    }
    tree->item -= 1;
    if (tree->item < 48) {
        tree->item += 10;
        overflow_neg(tree->right);
    }
}

btree_t **substitute(int n, char **nb, int c)
{
    int l = my_strlen(nb[1]);
    int res[3] = {0, 0, 0};
    char r;
    btree_t *tree = malloc(sizeof(btree_t));
    btree_t **start = &tree->left;

    for (int i = 0; i < l; i++) {
        res[0] = nb[1][i] - 48;
        res[1] = nb[2][i] - 48;
        res[2] = perform_sub(nb, c, res, tree);
        r = res[2] + 48;
        tree->left = btree_create_node(r);
        tree->left->right = tree;
        tree = tree->left;
    }
    return (start);
}
