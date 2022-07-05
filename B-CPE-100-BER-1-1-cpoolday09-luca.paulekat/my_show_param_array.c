/*
** EPITECH PROJECT, 2021
** my_show_param_array
** File description:
** displays array of my_params_to_array
*/
#include "include/my.h"

int my_show_param_array(struct info_param const *par)
{
    int i = 0;

    while (par[i].str != NULL) {
        my_putstr(par[i].copy);
        my_putchar('\n');
        my_put_nbr(par[i].length);
        my_putchar('\n');
        my_show_word_array(par[i].word_array);
        i++;
    }
    return (1);
}
