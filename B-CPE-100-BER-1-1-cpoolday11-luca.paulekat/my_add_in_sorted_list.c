/*
** EPITECH PROJECT, 2021
** my_add_in_sorted_list
** File description:
** adds an element in a sorted list
*/
#include "include/mylist.h"

linked_list_t *insert_before_first_el(linked_list_t *n, void *data, \
linked_list_t **begin, linked_list_t *ptr)
{
    n = malloc(sizeof(linked_list_t));
    n->data = data;
    n->next = *begin;
    ptr = n;
    return (ptr);
}

linked_list_t *insert_after_first_el(linked_list_t *n, void *data, \
linked_list_t **begin, linked_list_t *ptr)
{
    n = malloc(sizeof(linked_list_t));
    (*begin)->next = n;
    n->next = NULL;
    n->data = data;
    *begin = (*begin)->next;
    return (ptr);
}

linked_list_t *insert_mid_list(linked_list_t *n, void *data, \
linked_list_t **begin, linked_list_t *ptr)
{
    n = malloc(sizeof(linked_list_t));
    n->data = data;
    n->next = (*begin)->next;
    (*begin)->next = n;
    return (ptr);
}

void insert_end_list(linked_list_t *n, void *data, \
linked_list_t **begin, linked_list_t *ptr)
{
    n = malloc(sizeof(linked_list_t));
    n->data = data;
    (*begin)->next = n;
    n->next = NULL;
}

void my_add_in_sorted_list(linked_list_t **begin , void *data , int (*cmp)())
{
    linked_list_t *n;
    linked_list_t *ptr = *begin;

    if (cmp((*begin)->data, data) >= 0) {
        ptr = insert_before_first_el(n, data, begin, ptr);
        *begin = ptr;
        return;
    }
    while (*begin != NULL) {
        if ((*begin)->next != NULL && cmp((*begin)->next->data, data) >= 0) {
            ptr = insert_mid_list(n, data, begin, ptr);
            break;
        } else if ((*begin)->next == NULL && cmp((*begin)->data, data) < 0) {
            insert_end_list(n, data, begin, ptr);
        }
        *begin = (*begin)->next;
    }
    *begin = ptr;
}
