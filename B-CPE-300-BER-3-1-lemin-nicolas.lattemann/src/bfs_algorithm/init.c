/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include "lemin.h"
#include "queue.h"

void fill_array(int arr[], int value, int len)
{
    for (int i = 0; i < len; i++) {
        arr[i] = value;
    }
}

room_t *cast_ll(list_t *list)
{
    return list->item;
}

void flush_queue(room_t *queue[], int room_nbr)
{
    while (!queue_is_empty(queue)) {
        dequeue(queue, room_nbr);
    }
}

void init_arrs(int visited[], int trace[], room_t *queue[], int n_room)
{
    fill_array(visited, 0, n_room);
    fill_array(trace, -1, n_room);
    init_queue(queue, n_room);
}

void start_nested(list_t **lk_rooms, room_t *queue[], room_t **node, int n_room)
{
    *lk_rooms = queue[0]->next;
    *node = dequeue(queue, n_room);
    to_start(lk_rooms);
}
