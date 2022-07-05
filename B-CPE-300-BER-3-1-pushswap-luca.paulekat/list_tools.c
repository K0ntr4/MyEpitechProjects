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

linked_list_t *to_end(linked_list_t **l)
{
    while (*l && (*l)->next)
        *l = (*l)->next;
    return *l;
}

linked_list_t *to_start(linked_list_t **l)
{
    while (*l && (*l)->prev)
        *l = (*l)->prev;
    return *l;
}

linked_list_t *new_elem(void *data)
{
    linked_list_t *elem = malloc(sizeof(linked_list_t));

    if (!elem)
        return NULL;
    elem->next = NULL;
    elem->prev = NULL;
    elem->nb = my_getnbr(data);
    elem->data = data;
    return elem;
}

void append_item(linked_list_t **l, void *data)
{
    linked_list_t *elem = new_elem(data);

    if (!elem)
        return;
    if (!(*l)) {
        *l = elem;
        return;
    }
    to_end(l);
    elem->prev = *l;
    (*l)->next = elem;
}

void *pop(linked_list_t **l)
{
    void *data = NULL;
    linked_list_t *prev = NULL;

    to_end(l);
    data = (*l)->data;
    if ((*l)->prev)
        (*l)->prev->next = NULL;
    prev = (*l)->prev;
    free((*l));
    *l = prev;
    return data;
}
