/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include "lemin.h"

static void show_single_room(room_t *room)
{
    my_putstr("Room ");
    my_putstr(room->name);
    my_putstr(" with ID ");
    my_put_nbr(room->identifier);
    my_putchar('\n');
    my_putstr("anted: ");
    my_put_nbr(room->anted);
    my_putchar('\n');
    my_putstr("linked rooms:\n");
}

void show_room(room_t *room, int visited[])
{
    list_t *next = room->next;

    show_single_room(room);
    to_start(&next);
    while (next) {
        my_putchar('\t');
        my_putstr("Room ");
        my_putstr(((room_t *) next->item)->name);
        my_putstr(" with ID ");
        my_put_nbr(((room_t *) next->item)->identifier);
        my_putchar('\n');
        my_putstr("\tanted: ");
        my_put_nbr(((room_t *) next->item)->anted);
        my_putchar('\n');
        next = next->next;
    }
}
