/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/
#include "include/list.h"
#include <stddef.h>
#include <stdio.h>

unsigned int list_get_size(list_t list)
{
    int n = 0;

    if (list == NULL)
        return 0;
    while (list->next != NULL) {
        list = list->next;
        n++;
    }
    n++;
    return n;
}

bool list_is_empty(list_t list)
{
    if (list == NULL)
        return true;
    return false;
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    if (list == NULL)
        return;
    while (list->next != NULL) {
        val_disp(list->value);
        list = list->next;
    }
    val_disp(list->value);
}