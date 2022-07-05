/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/
#include "include/list.h"
#include <stddef.h>
#include <stdlib.h>

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t node = *front_ptr;

    if (node == NULL)
        return false;
    *front_ptr = node->next;
    free(node);
    return true;
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t node = *front_ptr;

    if (node == NULL)
        return false;
    if (node->next == NULL)
        node = NULL;
    while (node->next->next != NULL)
        node = node->next;
    free(node->next);
    node->next = NULL;
    return true;
}

void delete_node_generic(list_t *node, list_t *cpy)
{
    if (*node && (*node)->next)
        *cpy = (*node)->next->next;
    free((*node)->next);
    (*node)->next = *cpy;
}

bool list_del_elem_at_position(list_t *front_ptr, unsigned int position)
{
    unsigned int i = 0;
    list_t node = *front_ptr;
    list_t cpy;

    if (node == NULL)
        return false;
    if (position == 0)
        return list_del_elem_at_front(front_ptr);
    if (node->next == NULL)
        free(node);
    while (node->next != NULL && i + 1 != position)
        node = node->next;
    if (i + 1 != position)
        return false;
    delete_node_generic(&node, &cpy);
    return true;
}

void list_clear(list_t *front)
{
    list_t cpy = NULL;
    list_t node = *front;

    while (node && node->next) {
        cpy = node;
        node = node->next;
        free (cpy);
    }
    free(node);
    *front = NULL;
}
