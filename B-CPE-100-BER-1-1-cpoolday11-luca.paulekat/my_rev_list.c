/*
** EPITECH PROJECT, 2021
** my_rev_list
** File description:
** reverses a list
*/
#include "include/mylist.h"

void my_rev_list(linked_list_t ** begin)
{
    linked_list_t *l = *begin;
    linked_list_t *prev;
    linked_list_t *n = NULL;

    for (int i = 0; l->next != NULL; i++) {
        prev = l->next;
        l->next = n;
        n = l;
        l = prev;
    }
    l->next = n;
    *begin = l;
}
