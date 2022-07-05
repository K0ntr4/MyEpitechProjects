/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include "ants.h"

int is_next_room(room_t *next_room, ant_t *ant)
{
    int cond1 = ant->path && next_room->identifier == ant->path[1];
    int cond2 = !next_room->anted;
    int cond3 = next_room->special != DEFAULT_ROOM;

    return cond1 && (cond2 || cond3);
}

int get_next_room(ant_t *ant, int moved)
{
    list_t *linked_room = ant->room->next;

    to_start(&linked_room);
    while (linked_room) {
        if (is_next_room(linked_room->item, ant)) {
            ant->room->anted = 0;
            ant->room = linked_room->item;
            ant->room->anted = 1;
            show_ant_movement(ant, moved);
            return 1;
        }
        linked_room = linked_room->next;
    }
    return 0;
}

void move_ants(ant_t **ants, int n_room)
{
    int moved = 0;

    for (int i = 0; ants[i]; i++) {
        if (one_at_end(ants[i]))
            continue;
        if (cal_paths(ants[i]->room, ants[i], n_room, NULL) == 4)
            continue;
        moved = get_next_room(ants[i], moved) ? 1 : moved;
    }
    if (moved)
        my_putchar('\n');
}

int path(ant_t **ants, int n_room)
{
    while (!all_at_end(ants)) {
        move_ants(ants, n_room);
    }
    return 0;
}
