/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <lemin.h>

void free_list_validation(list_t *list)
{
    list_t *next = NULL;
    char **item;

    if (!list)
        return;
    to_start(&list);
    while (list) {
        next = list->next;
        item = list->item;
        for (int i = 0; item[i]; i++)
            free(item[i]);
        free(list->item);
        free(list);
        list = next;
    }
}
