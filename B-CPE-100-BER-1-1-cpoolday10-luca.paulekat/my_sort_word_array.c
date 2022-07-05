/*
** EPITECH PROJECT, 2021
** my_sort_word_array
** File description:
** sorts a word array by ascii
*/
#include <stdlib.h>
#include "include/my.h"

int my_sort_word_array(char **tab)
{
    char *p;
    int i = 0;
    int counter = 0;

    while (tab[i + 1] != NULL) {
        if (my_strcmp(tab[i], tab[i + 1]) > 0) {
            p = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = p;
            counter++;
        }
        i++;
    }
    if (counter != 0)
        my_sort_word_array(tab);
    else {
        return (0);
    }
    return (0);
}
