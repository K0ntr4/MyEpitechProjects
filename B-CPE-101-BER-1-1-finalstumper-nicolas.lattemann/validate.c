/*
** EPITECH PROJECT, 2021
** Stumper
** File description:
** desc
*/

#include <stddef.h>
#include <stdlib.h>
#include "header.h"
#include "my.h"

char *get_set(char **arr, int x, int y)
{
    char set1[6] = "oo-| \0";
    char set2[6] = "/\\** \0";
    char set3[6] = "ACBB \0";
    char *set = NULL;
    int c = 0;

    if (x == 1 || y == 1)
        c = 3;
    set = arr[0][0] == set1[0] ? my_strdup(set1) : set;
    set = arr[0][0] == set2[c] ? my_strdup(set2) : set;
    set = arr[0][0] == set3[c] ? my_strdup(set3) : set;
    return set;
}

int validate2(char **arr, int x, int y, int i)
{
    int val = 1;
    char *set = get_set(arr, x, y);
    int spa = 0;
    int sid = 0;
    int top = 0;

    for (int j = 0; j < x && val; j++) {
        spa = 0 < j && j < x - 1 && 0 < i && i < y - 1;
        sid = (j == 0 || j == x - 1) && (0 < i && i < y - 1);
        top = (0 < j && j < x - 1) && (0 == i || i == y - 1);
        val = includes(set, arr[i][j]);
        if (x > 2 && top)
            val = val && arr[i][j] == set[2] ? 1 : 0;
        if (y > 2 && sid)
            val = val && arr[i][j] == set[3] ? 1 : 0;
        if (y > 2 && x > 2 && spa)
            val = val && arr[i][j] == ' ' ? 1 : 0;
    }
    free(set);
    return val;
}

int validate(char **arr, int x, int y)
{
    int val = 1;
    char *set = get_set(arr, x, y);

    if (set == NULL)
        return 84;
    for (int i = 0; i < y && val; i++) {
        val = validate2(arr, x, y, i);
    }
    free(set);
    return val ? 0 : 84;
}
