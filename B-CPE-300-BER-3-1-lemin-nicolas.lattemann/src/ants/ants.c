/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "lemin.h"
#include "ants.h"

ant_t *gen_ant(int n, room_t *room)
{
    ant_t *ant = malloc(sizeof(ant_t));

    ant->nbr = n;
    ant->room = room;
    ant->path = NULL;
    return ant;
}

ant_t **init_ants(room_t *start, int n)
{
    ant_t **ants = malloc(sizeof(ant_t *) * (n + 1));

    for (int i = 0; i < n; i++)
        ants[i] = gen_ant(i + 1, start);
    ants[n] = NULL;
    return ants;
}

void free_ants(ant_t **ants)
{
    for (int i = 0; ants[i]; i++) {
        free(ants[i]->path);
        free(ants[i]);
    }
    free(ants);
}

int all_at_end(ant_t **ants)
{
    for (int i = 0; ants[i]; i++) {
        if (ants[i]->room->special != END_ROOM)
            return 0;
    }
    return 1;
}

int one_at_end(ant_t *ant)
{
    if (ant->room->special == END_ROOM)
        return 1;
    return 0;
}
