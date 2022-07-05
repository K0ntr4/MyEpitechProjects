/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include "ants.h"

void show_path(ant_t *ant)
{
    for (int i = 0; ant->path[i] != -1; i++) {
        my_put_nbr(ant->path[i]);
        if (ant->path[i + 1] != -1)
            my_putstr("->");
    }
    my_putchar('\n');
}

void show_ant_info(ant_t **ants)
{
    for (int i = 0; ants[i]; i++) {
        my_putstr("Ant nbr ");
        my_put_nbr(ants[i]->nbr);
        my_putstr(" is in room nbr ");
        my_putstr(ants[i]->room->name);
        my_putstr("\n");
    }
}

void show_ant_movement(ant_t *ant, int moved)
{
    if (moved)
        my_putchar(' ');
    my_putchar('P');
    my_put_nbr(ant->nbr);
    my_putchar('-');
    my_putstr(ant->room->name);
}
