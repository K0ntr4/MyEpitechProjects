/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "lemin.h"

void enqueue(room_t *room, room_t *queue[], int queue_len)
{
    for (int i = 0; i < queue_len; i++) {
        if (queue[i] == NULL) {
            queue[i] = room;
            return;
        }
    }
}

room_t *dequeue(room_t *queue[], int queue_len)
{
    room_t *ret_val = queue[0];

    for (int i = 0; i < queue_len; i++) {
        queue[i] = i == queue_len ? NULL : queue[i + 1];
    }
    return ret_val;
}

int queue_is_empty(room_t *queue[])
{
    if (queue[0] == NULL)
        return 1;
    return 0;
}

void init_queue(room_t *queue[], int queue_len)
{
    for (int i = 0; i < queue_len; i++)
        queue[i] = NULL;
}
