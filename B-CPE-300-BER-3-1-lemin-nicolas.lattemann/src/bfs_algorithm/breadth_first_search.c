/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include "lemin.h"
#include "queue.h"
#include "ants.h"

int update_ant_path(ant_t *ant, int end_room, const int trace[], int n_room)
{
    int *path = NULL;
    int reversed_path[n_room];
    int path_len = 0;

    for (int i = 0; i < n_room; i++)
        reversed_path[i] = -1;
    for (int i = 0; i < n_room && end_room != -1; i++) {
        reversed_path[i] = end_room;
        end_room = trace[end_room];
    }
    for (; reversed_path[path_len] != -1; path_len++);
    path = malloc(sizeof(int) * (path_len + 1));
    for (int i = 0; i < path_len; i++)
        path[path_len - i - 1] = reversed_path[i];
    path[path_len] = -1;
    if (ant->path != NULL)
        free(ant->path);
    ant->path = path;
    return 0;
}

int check_all_anted(list_t *next_rooms)
{
    room_t *room = NULL;
    int ret_val = 1;

    to_start(&next_rooms);
    while (next_rooms) {
        room = next_rooms->item;
        if (!room->anted || room->special != DEFAULT_ROOM) {
            ret_val = 0;
            break;
        }
        next_rooms = next_rooms->next;
    }
    return ret_val;
}

int valid_room(const int visited[], room_t *next_node, list_t *linked_rooms)
{
    int cond1 = !visited[next_node->identifier];
    int cond2 = check_all_anted(linked_rooms);
    int cond3 = !check_all_anted(linked_rooms) && !next_node->anted;
    int cond4 = next_node->special != DEFAULT_ROOM;

    return cond1 && ((cond2 || cond3) || cond4);
}

int cal_paths(room_t *node, ant_t *ant, int n_room, list_t *linked_rooms)
{
    room_t *queue[n_room];
    int trace[n_room];
    int end_room = -1;
    int visited[n_room];

    init_arrs(visited, trace, queue, n_room);
    fill_queue(node, queue, n_room, visited);
    while (!queue_is_empty(queue)) {
        start_nested(&linked_rooms, queue, &node, n_room);
        while (linked_rooms) {
            if (valid_room(visited, linked_rooms->item, linked_rooms)) {
                enqueue(linked_rooms->item, queue, n_room);
                trace[cast_ll(linked_rooms)->identifier] = node->identifier;
                if (at_end(linked_rooms, queue, n_room, &end_room))
                    break;
            }
            iterate_and_mark_visited(visited, &linked_rooms);
        }
    }
    return end_room == -1 ? -1 : update_ant_path(ant, end_room, trace, n_room);
}
