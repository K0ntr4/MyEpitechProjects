/*
** EPITECH PROJECT, 2021
** my_sort_list
** File description:
** sorts a list in ascending order
*/
#include "include/mylist.h"

void my_sort_list(linked_list_t **begin , int (*cmp)())
{
    linked_list_t *tmp;
    long ptr = &(**begin);
    int counter = 0;

    for (int i = 0; *begin != NULL && (*begin)->next != NULL; i++) {
        if (cmp((*begin)->data, (*begin)->next->data) > 0) {
            tmp = (*begin)->data;
            (*begin)->data = (*begin)->next->data;
            (*begin)->next->data = tmp;
            counter++;
        }
        *begin = (*begin)->next;
    }
    *begin = ptr;
    if (counter != 0)
        my_sort_list(begin, cmp);
}
