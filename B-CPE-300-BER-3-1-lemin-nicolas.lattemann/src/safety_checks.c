/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include "lemin.h"
#include "ants.h"

int safety_checks(room_t *start, int n_room)
{
    ant_t *mock_ant = gen_ant(0, NULL);

    if (cal_paths(start, mock_ant, n_room, NULL) == -1)
        return my_puterror("Start and end are not connected to each other.\n");
    free(mock_ant->path);
    free(mock_ant);
    return 0;
}
