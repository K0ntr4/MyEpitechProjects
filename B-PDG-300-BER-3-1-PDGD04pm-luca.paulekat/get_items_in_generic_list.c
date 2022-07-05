/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/
#include "include/list.h"
#include <stddef.h>
#include <stdlib.h>

void *list_get_elem_at_front(list_t list)
{
    if (list == NULL)
        return 0;
    return list->value;
}

void *list_get_elem_at_back(list_t list)
{
    if (list == NULL)
        return 0;
    while (list->next)
        list = list->next;
    return list->value;
}

void *list_get_elem_at_position(list_t list, unsigned int position)
{
    unsigned int i = 0;

    if (list == NULL)
        return 0;
    if (position == 0)
        return list_get_elem_at_front(list);
    while (list->next && i <= position - 1) {
        list = list->next;
        i++;
    }
    if (i != position)
        return 0;
    return list->value;
}