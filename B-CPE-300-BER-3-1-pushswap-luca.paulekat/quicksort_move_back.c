/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** desc
*/

#include "mylist.h"
#include "my.h"

linked_list_t *recurse_qs(linked_list_t **l, linked_list_t **l2, \
    int *n, linked_list_t *print_list)
{
    n[4] += 1;
    quicksort_list(l2, l, n, print_list);
    return *l;
}
