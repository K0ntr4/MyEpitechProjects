/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/
#include "include/list.h"
#include <stddef.h>
#include <stdlib.h>

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    list_t new_node = malloc(sizeof(node_t));

    if (new_node == NULL)
        return false;
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    list_t new_node = malloc(sizeof(node_t));
    list_t node = *front_ptr;

    if (new_node == NULL)
        return false;
    new_node->value = elem;
    new_node->next = NULL;
    if (node == NULL) {
        *front_ptr = new_node;
        return true;
    }
    while (node != NULL && node->next != NULL)
        node = node->next;
    node->next = new_node;
    return true;
}

void implement_middle_node_generic(list_t *cpy, list_t *node,
    list_t *new_node)
{
    *cpy = (*node)->next;
    (*node)->next = *new_node;
    (*new_node)->next = *cpy;
}

int go_to_next_node_generic(list_t *node)
{
    *node = (*node)->next;
    return 1;
}

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
    unsigned int pos)
{
    list_t new_node = NULL;
    unsigned int i = 0;
    list_t node = *front_ptr;
    list_t cpy = NULL;

    if (pos == 0 || node == NULL)
        return list_add_elem_at_front(front_ptr, elem);
    if (pos == list_get_size(node))
        return list_del_elem_at_back(front_ptr);
    while (node && node->next && i < pos - 1)
        i += go_to_next_node_generic(&node);
    if (i != pos - 1)
        return false;
    new_node = malloc(sizeof(node_t));
    new_node->value = elem;
    new_node->next = NULL;
    if (new_node == NULL)
        return false;
    implement_middle_node_generic(&cpy, &node, &new_node);
    return true;
}
