/*
** EPITECH PROJECT, 2021
** my_delete_nodes
** File description:
** deletes matching nodes
*/
#include "include/mylist.h"

int deleting_loop(linked_list_t **begin, int (*cmp)(), void const *datar, int c)
{
    while (*begin != NULL) {
        if ((*begin)->next != NULL && cmp((*begin)->next->data, datar) == 0) {
            (*begin)->next = (*begin)->next->next;
            c++;
        }
        *begin = (*begin)->next;
    }
    return (c);
}

int my_delete_nodes(linked_list_t **begin , void const *data_ref , int (*cmp)())
{
    int counter = 0;
    long ptr = &(**begin);

    if ((*begin)->next == NULL && cmp((*begin)->data, data_ref) == 0) {
        *begin = NULL;
        ptr = *begin;
    } else if (cmp((*begin)->data, data_ref) == 0) {
        *begin = (*begin)->next;
        ptr = &(**begin);
        counter++;
    }
    counter += deleting_loop(begin, cmp, data_ref, counter);
    *begin = ptr;
    if (counter != 0)
        my_delete_nodes(begin, data_ref, cmp);
    return (0);
}
