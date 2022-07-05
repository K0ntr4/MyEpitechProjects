/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include <stddef.h>
#include <stdlib.h>

#include "my.h"
#include "mylist.h"

int print_l(linked_list_t **l)
{
    linked_list_t *copy = *l;
    to_start(&copy);

    while (copy) {
        my_putstr((char *)copy->data);
        copy = copy->next;
        if (copy)
            my_putchar(' ');
    }
    my_putchar('\n');
    free(copy);
    return 0;
}

void *peek(linked_list_t *l)
{
    to_end(&l);
    return l->data;
}

void free_l(linked_list_t *l)
{
    if (!l)
        return;
    to_start(&l);
    while (l->next) {
        l = l->next;
        free(l->prev->data);
        free(l->prev);
    }
    free(l->data);
    free(l);
}

linked_list_t *remove_placeholder_l(linked_list_t **l)
{
    linked_list_t *tmp = NULL;

    while (*l && (*l)->next) {
        if (my_strcmp((*l)->data, " ") == 0) {
            tmp = (*l)->prev;
            *l = (*l)->next;
            free((*l)->prev->data);
            free((*l)->prev);
            (*l)->prev = tmp;
        } else {
            *l = (*l)->next;
        }
    }
    if (my_strcmp((*l)->data, " ") == 0 && (*l)->prev != NULL) {
        *l = (*l)->prev;
        free((*l)->next->data);
        free((*l)->next);
        (*l)->next = NULL;
    }
    return *l;
}

linked_list_t *to_unsorted(linked_list_t *l)
{
    for (int j = 1; l->next != NULL && my_getnbr(l->data) <= \
        my_getnbr(l->next->data);) {
        l = l->next;
    }
    return l;
}
