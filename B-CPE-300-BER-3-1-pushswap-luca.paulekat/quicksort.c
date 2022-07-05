/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** desc
*/

#include "mylist.h"
#include "my.h"

int check_list(linked_list_t *l, int i)
{
    int c = 0;

    l = remove_placeholder_l(&l);
    if (i == -1)
        i = my_list_size(l);
    to_start(&l);
    while (l && (l)->next && i != 0 && c == 0) {
        if (l->nb <= l->next->nb || my_strcmp(l->next->data, " ") == 0)
            ;
        else
            c = 1;
        l = (l)->next;
        i--;
    }
    return c;
}

char *get_print(int called)
{
    if (called % 2 == 0)
        return "a";
    if (called % 2 == 1)
        return "b";
}

linked_list_t *move_to_back(linked_list_t **l, linked_list_t **l2, \
    int *n, linked_list_t *print_list)
{
    while (n[0] <= (*l)->nb && n[6] <= n[1] - n[5] \
        && my_strcmp((*l)->data, " ")) {
        *l2 = move_to_first_of_list(l, *l2, get_print(n[4] + 1), print_list);
        if (my_list_size(*l2) > 1)
            move_to_end(*l2, get_print(n[4] + 1), print_list);
        n[6] += 1;
        n[3]++;
    }
    n[6] -= 1;
    return *l2;
}

void move_elements(linked_list_t **l, linked_list_t **l2, \
    int *n, linked_list_t *print_list)
{
    *l = to_unsorted(*l);
    n[0] = (*l)->nb;
    to_start(l);
    for (; n[6] <= n[1] && my_strcmp((*l)->data, " ") != 0; n[6] += 1) {
        if (n[0] > (*l)->nb) {
            *l2 = move_to_first_of_list(l, *l2, get_print(n[4] + 1), \
                print_list);
            n[2]++;
        } else {
            *l2 = move_to_back(l, l2, n, print_list);
        }
    }
    n[6] = 0;
}

linked_list_t *quicksort_list(linked_list_t **l, linked_list_t **l2, \
    int *x, linked_list_t *print_list)
{
    char *print = get_print(x[4]);
    int n[7] = {0, 0, 0, 0, x[4], x[5], 0};

    n[1] = n[5] != 0 ? n[5] : my_list_size(*l);
    to_start(l);
    if (check_list(*l, -1) == 0)
        return *l;
    if (my_list_size(*l2) == 1 && my_strcmp((*l2)->data, " ") == 0)
        n[5] = 0;
    move_elements(l, l2, n, print_list);
    if (check_list(*l2, -1) == 0)
        return *l2;
    recurse_qs(l, l2, n, print_list);
    return *l2;
}
