/*
** EPITECH PROJECT, 2021
** my_apply_on_nodes
** File description:
** applies a function on all nodes
*/
#include "include/mylist.h"

int my_apply_on_nodes(linked_list_t *begin , int (*f)(void *))
{
    for (int i = 0; begin != NULL; i++) {
        f(begin->data);
        begin = begin->next;
    }
    return (0);
}
