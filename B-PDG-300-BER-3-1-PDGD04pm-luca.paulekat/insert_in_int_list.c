/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/
#include "include/int_list.h"
#include <stddef.h>
#include <stdlib.h>

bool int_list_add_elem_at_front(int_list_t *front_ptr, int elem)
{
    int_list_t new_node = malloc(sizeof(int_node_t));

    if (new_node == NULL)
        return false;
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return true;
}

bool int_list_add_elem_at_back(int_list_t *front_ptr, int elem)
{
    int_list_t new_node = malloc(sizeof(int_node_t));
    int_list_t node = *front_ptr;

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

void implement_middle_node(int_list_t *cpy, int_list_t *node,
    int_list_t *new_node)
{
    *cpy = (*node)->next;
    (*node)->next = *new_node;
    (*new_node)->next = *cpy;
}

int go_to_next_node(int_list_t *node)
{
    *node = (*node)->next;
    return 1;
}

bool int_list_add_elem_at_position(int_list_t *front_ptr, int elem,
    unsigned int position)
{
    int_list_t new_node = NULL;
    unsigned int i = 0;
    int_list_t node = *front_ptr;
    int_list_t cpy = NULL;

    if (position == 0 || node == NULL)
        return int_list_add_elem_at_front(front_ptr, elem);
    while (node && node->next && i < position - 1)
        i += go_to_next_node(&node);
    if (i != position - 1)
        return false;
    new_node = malloc(sizeof(int_node_t));
    new_node->value = elem;
    new_node->next = NULL;
    if (new_node == NULL)
        return false;
    implement_middle_node(&cpy, &node, &new_node);
    return true;
}
