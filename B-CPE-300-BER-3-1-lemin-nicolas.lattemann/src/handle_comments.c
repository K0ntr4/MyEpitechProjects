/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <lemin.h>

int comments_after_command(char **str, int j)
{
    int i = 1;

    while (str[j - i]) {
        if (str[j - i][0] == '#' && my_strcmp(str[j - i], \
            "##start") != 0 && my_strcmp(str[j - i], "##end") != 0)
            i++;
        else
            return i;
    }
    return i;
}

int comments_before_ants(char **str)
{
    int i = 0;

    while (str[i]) {
        if (str[i][0] == '#' && my_strcmp(str[i], \
            "##start") != 0 && my_strcmp(str[i], "##end") != 0)
            i++;
        else
            return i;
    }
    return i;
}
