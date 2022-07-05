/*
** EPITECH PROJECT, 2021
** SHARED
** File description:
** shated functions
*/

#include <stdlib.h>

#include "my.h"
#include "header.h"

void rem_zer(char *str)
{
    int i = 0;
    int found = 0;

    while (str[i]) {
        if (1 <= to_i(str[i]) && to_i(str[i]) <= 9)
            found = 1;
        else if (found == 0)
            str[i] = str[i + 1];
        i++;
    }
}
