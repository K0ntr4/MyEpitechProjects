/*
** EPITECH PROJECT, 2021
** my_apply_on_matching_nodes
** File description:
** applies a function on matching nodes
*/
#include "include/mylist.h"

int my_apply_on_matching_nodes(linked_list_t *begin , int (*f)(), \
void const *data_ref, int (*cmp)())
{
    for (int i = 0; begin != NULL; i++) {
        if (cmp(begin->data, data_ref) == 0)
            f(begin->data);
        begin = begin->next;
    }
    return (0);
}
