/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include "lemin.h"

#ifndef B_CPE_300_BER_3_1_BSLEMIN_NICOLAS_LATTEMANN_ANTS_H
    #define B_CPE_300_BER_3_1_BSLEMIN_NICOLAS_LATTEMANN_ANTS_H

typedef struct ant {
    int nbr;
    room_t *room;
    int *path;
} ant_t;

ant_t **init_ants(room_t *start, int n);

int path(ant_t **ants, int n_room);

int cal_paths(room_t *node, ant_t *ant, int n_room, list_t *linked_rooms);

void show_ant_movement(ant_t *ant, int moved);

ant_t *gen_ant(int n, room_t *room);

void free_ants(ant_t **ants);

void show_path(ant_t *ant);

int all_at_end(ant_t **ants);

int one_at_end(ant_t *ant);

#endif //B_CPE_300_BER_3_1_BSLEMIN_NICOLAS_LATTEMANN_ANTS_H
