/*
** EPITECH PROJECT, 2021
** my_sort_word_array
** File description:
** sorts a word array by ascii
*/
#include <stdlib.h>
#include "include/my.h"

int my_advanced_sort_word_array(char **t , int(*c)(char const *, char const *))
{
    char *p;
    int i = 0;
    int counter = 0;

    while (t[i + 1] != NULL) {
        if (c(t[i], t[i + 1]) > 0) {
            p = t[i];
            t[i] = t[i + 1];
            t[i + 1] = p;
            counter++;
        }
        i++;
    }
    if (counter != 0)
        my_advanced_sort_word_array(t, c);
    else
        return (0);
    return (84);
}
