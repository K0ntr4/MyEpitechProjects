/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/
#include "include/int_list.h"
#include <stddef.h>

int int_list_get_elem_at_front(int_list_t list)
{
    if (list == NULL)
        return 0;
    return list->value;
}

int int_list_get_elem_at_back(int_list_t list)
{
    if (list == NULL)
        return 0;
    while (list->next)
        list = list->next;
    return list->value;
}

int int_list_get_elem_at_position(int_list_t list, unsigned int position)
{
    unsigned int i = 0;

    if (list == NULL)
        return 0;
    if (position == 0)
        return int_list_get_elem_at_front(list);
    while (list->next && i <= position - 1) {
        list = list->next;
        i++;
    }
    if (i != position)
        return 0;
    return list->value;
}
