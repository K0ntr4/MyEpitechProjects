/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include <stddef.h>
#include <stdlib.h>

#include "my.h"
#include "header.h"
#include "parser.h"

list_t *to_end(list_t **list)
{
    while (*list && (*list)->next)
        *list = (*list)->next;
    return *list;
}

list_t *to_start(list_t **list)
{
    while (*list && (*list)->prev)
        *list = (*list)->prev;
    return *list;
}

list_t *new_elem(void *item)
{
    list_t *elem = malloc(sizeof(list_t));

    if (!elem)
        return NULL;
    elem->next = NULL;
    elem->prev = NULL;
    elem->item = item;
    return elem;
}

void append_item(list_t **list, void *item)
{
    list_t *elem = new_elem(item);

    if (!elem)
        return;
    if (!(*list)) {
        *list = elem;
        return;
    }
    to_end(list);
    elem->prev = *list;
    (*list)->next = elem;
}

void *pop(list_t **list)
{
    void *item = NULL;
    list_t *prev = NULL;

    to_end(list);
    item = (*list)->item;
    if ((*list)->prev)
        (*list)->prev->next = NULL;
    prev = (*list)->prev;
    free((*list));
    *list = prev;
    return item;
}
