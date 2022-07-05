/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/
#include "include/queue.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void queue_clear(queue_t *queue_ptr)
{
    return list_clear(queue_ptr);
}

bool queue_pop(queue_t *queue_ptr)
{
    return list_del_elem_at_front(queue_ptr);
}

bool queue_push(queue_t *queue_ptr, void *elem)
{
    return list_add_elem_at_back(queue_ptr, elem);
}

void *queue_front(queue_t queue)
{
    return list_get_elem_at_front(queue);
}
