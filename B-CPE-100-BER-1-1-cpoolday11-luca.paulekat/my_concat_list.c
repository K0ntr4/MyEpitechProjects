/*
** EPITECH PROJECT, 2021
** my_concat_list
** File description:
** concats two lists
*/
#include "include/mylist.h"

void my_concat_list(linked_list_t **begin1 , linked_list_t *begin2)
{
    long ptr = &(**begin1);

    for (int i = 0; begin1 != NULL; i++) {
        if ((*begin1)->next != NULL)
            *begin1 = (*begin1)->next;
        else
            break;
    }
    (*begin1)->next = begin2;
    *begin1 = ptr;
}
