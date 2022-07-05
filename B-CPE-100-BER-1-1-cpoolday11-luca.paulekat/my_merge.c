/*
** EPITECH PROJECT, 2021
** my_merge
** File description:
** merges a list into another sorted list
*/
#include "include/mylist.h"

void my_add_in_sorted_list(linked_list_t **begin , void *data , int (*cmp)());

void my_merge(linked_list_t **begin1 , linked_list_t *begin2 , int (*cmp)())
{
    for (int i = 0; begin2 != NULL; i++) {
        my_add_in_sorted_list(begin1 , begin2->data , cmp);
        begin2 = begin2->next;
    }
}
