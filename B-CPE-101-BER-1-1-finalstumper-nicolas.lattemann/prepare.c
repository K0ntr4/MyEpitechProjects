/*
** EPITECH PROJECT, 2021
** Stumper
** File description:
** desc
*/

#include "my.h"
#include "stdlib.h"
#include "header.h"

char **alloc_array(int x, int y)
{
    char **arr = malloc(sizeof(char *) * y);

    if (!arr)
        return NULL;
    for (int i = 0; i < y; i++) {
        arr[i] = malloc(sizeof(char) * x);
        if (arr[i] == NULL)
            return NULL;
    }
    return arr;
}

char **to_twodarray(char *buff, int x, int y)
{
    char **arr = alloc_array(x, y);
    int h = 0;
    int g = 0;

    if (!arr)
        return NULL;
    for (int i = 0; buff[i + 1]; i++) {
        if (buff[i] == '\n' && buff[i + 1]) {
            h = 0;
            g++;
            continue;
        }
        arr[g][h] = buff[i];
        h++;
    }
    return arr;
}

void show_twodarray(char **arr, int x, int y)
{
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++)
            my_putchar(arr[i][j]);
        my_putchar('\n');
    }
}
