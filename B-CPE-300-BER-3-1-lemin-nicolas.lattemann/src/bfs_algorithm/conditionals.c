/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include "lemin.h"
#include "queue.h"

int at_end(list_t *linked_rooms, room_t *queue[], int n_room, int *end_room)
{
    if (cast_ll(linked_rooms)->special == END_ROOM) {
        *end_room = cast_ll(linked_rooms)->identifier;
        flush_queue(queue, n_room);
        return 1;
    }
    return 0;
}

void iterate_and_mark_visited(int visited[], list_t **linked_rooms)
{
    visited[cast_ll(*linked_rooms)->identifier] = 1;
    *linked_rooms = (*linked_rooms)->next;
}

void fill_queue(room_t *node, room_t *queue[], int n_room, int visited[])
{
    enqueue(node, queue, n_room);
    visited[queue[0]->identifier] = 1;
}
