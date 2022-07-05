/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/
#include "include/queue.h"
#include <stddef.h>
#include <stdio.h>

unsigned int queue_get_size(queue_t queue)
{
    return list_get_size(queue);
}

bool queue_is_empty(queue_t queue)
{
    return list_is_empty(queue);
}
