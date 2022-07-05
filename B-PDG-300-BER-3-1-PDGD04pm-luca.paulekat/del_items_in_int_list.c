/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/
#include "include/int_list.h"
#include <stddef.h>
#include <stdlib.h>

bool int_list_del_elem_at_front(int_list_t *front_ptr)
{
    int_list_t node = *front_ptr;

    if (node == NULL)
        return false;
    *front_ptr = node->next;
    free(node);
    return true;
}

bool int_list_del_elem_at_back(int_list_t *front_ptr)
{
    int_list_t node = *front_ptr;

    if (node == NULL)
        return false;
    if (node->next == NULL)
        free(node);
    while (node->next->next != NULL)
        node = node->next;
    free(node->next);
    node->next = NULL;
    return true;
}

void delete_node(int_list_t *node, int_list_t *cpy)
{
    if (*node && (*node)->next)
        *cpy = (*node)->next->next;
    free((*node)->next);
    (*node)->next = *cpy;
}

bool int_list_del_elem_at_position(int_list_t *front_ptr,
    unsigned int position)
{
    unsigned int i = 0;
    int_list_t node = *front_ptr;
    int_list_t cpy = NULL;

    if (node == NULL)
        return false;
    if (position == 0)
        return int_list_del_elem_at_front(front_ptr);
    if (node->next == NULL)
        free(node);
    while (node->next != NULL && i + 1 != position) {
        node = node->next;
        i++;
    }
    if (i + 1 != position)
        return false;
    delete_node(&node, &cpy);
    return true;
}

void int_list_clear(int_list_t *front_ptr)
{
    int_list_t cpy = NULL;
    int_list_t node = *front_ptr;

    while (node && node->next) {
        cpy = node;
        node = node->next;
        free (cpy);
    }
    free(node);
    *front_ptr = NULL;
}
