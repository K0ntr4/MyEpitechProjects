/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <lemin.h>
#include "ants.h"

void final_free(char **input, ant_t **ants)
{
    for (int i = 0; i < arr_length((const char **) input); i++)
        free(input[i]);
    free(input);
    free_ants(ants);
}

int main(__attribute__((unused)) int argc, __attribute__((unused)) char **argv)
{
    char **input = read_input();
    room_t *start;
    int n_room = 1;
    ant_t **ants;
    int n_ant = my_getnbr(input[comments_before_ants(input)]);

    if (validate_str(input) == 1 || n_ant <= 0)
        return 84;
    show_input((const char **) input);
    if ((start = parse_input(input, &n_room)) == NULL)
        return 0;
    if (validate_str(input) == 2)
        return 0;
    ants = init_ants(start, n_ant);
    if (safety_checks(start, n_room) == 84)
        return 84;
    path(ants, n_room);
    final_free(input, ants);
    return 0;
}
