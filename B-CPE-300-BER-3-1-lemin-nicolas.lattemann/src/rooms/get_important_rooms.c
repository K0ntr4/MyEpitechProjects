/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <lemin.h>

room_t *returning_start_room(room_t **links)
{
    int start = 0;

    for (; links[start] != NULL && links[start]->special != 1; start++);
    return links[start];
}

void get_linking_rooms(room_t **links, char **tmp, int *n)
{
    n[2] = 0;
    n[3] = 0;
    while (links[n[2]] != NULL && my_strcmp(links[n[2]]->name, tmp[0]) != 0) {
        n[2] += 1;
    }
    while (links[n[3]] != NULL && my_strcmp(links[n[3]]->name, tmp[1]) != 0) {
        n[3] += 1;
    }
}
