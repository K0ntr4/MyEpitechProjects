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

int print_list(list_t **list)
{
    list_t *copy = *list;
    to_start(&copy);

    while (copy) {
        my_putstr((char *)copy->item);
        copy = copy->next;
        if (copy)
            my_putchar(' ');
    }
    my_putchar('\n');
    free(copy);
    return 0;
}

void *peek(list_t *list)
{
    to_end(&list);
    return list->item;
}

void free_list(list_t *list)
{
    if (!list)
        return;
    to_start(&list);
    while (list) {
        list = list->next;
        free(list->prev->item);
        free(list->prev);
    }
}
