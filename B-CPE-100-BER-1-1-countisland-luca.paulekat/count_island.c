/*
** EPITECH PROJECT, 2021
** count_island
** File description:
** counts groups of x inside 2 dim array
*/
#include "include/my.h"

int replace(int island_counter, char **world, int i, int j)
{
    if ((world[i][j] == 'x' || world[i][j] == 'X') && (world[i][j] != '\0')) {
        world[i][j] = island_counter + 48;
        if (i > 0)
            replace(island_counter, world, i - 1, j);
        if (j > 0)
            replace(island_counter, world, i, j - 1);
        if (world[i + 1] != NULL)
            replace(island_counter, world, i + 1, j);
        if (world[i][j + 1] != '\0')
            replace(island_counter, world, i, j + 1);
        return (1);
    } else {
        ;
    }
    return (0);
}

int count_island(char **world)
{
    int i = 0;
    int j = 0;
    int counter = 0;

    while (world[i] != NULL) {
        while (world[i][j] != '\0') {
            counter += replace(counter, world, i, j);
            j++;
        }
        i++;
        j = 0;
    }
    return (counter);
}
