/*
** EPITECH PROJECT, 2021
** my_find_node
** File description:
** returns the adress of a matching element of a list
*/
#include "include/mylist.h"

linked_list_t *my_find_node(linked_list_t const *begin, void const *data_ref, \
int (*cmp)())
{
    linked_list_t *l;

    for (int i = 0; begin != NULL; i++) {
        if (cmp(begin->data, data_ref) == 0)
            return (begin);
        begin = begin->next;
    }
    return (NULL);
}
