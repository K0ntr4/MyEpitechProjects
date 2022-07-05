/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/
#include "include/int_list.h"
#include <stddef.h>
#include <stdio.h>

bool int_list_is_empty(int_list_t list)
{
    if (list == NULL)
        return true;
    return false;
}

unsigned int int_list_get_size(int_list_t list)
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

void int_list_dump(int_list_t list)
{
    if (int_list_is_empty(list) == true)
        return;
    while (list->next != NULL) {
        printf("%d\n", list->value);
        list = list->next;
    }
    printf("%d\n", list->value);
}
