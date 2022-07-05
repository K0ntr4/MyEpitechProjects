/*
** EPITECH PROJECT, 2021
** my_params_to_array
** File description:
** transforms parameters into an array
*/
#include "include/my.h"

struct info_param *my_params_to_array(int ac , char **av)
{
    int i = 0;

    struct info_param *p = malloc((ac + 1) * sizeof(struct info_param));
    while (i < ac) {
        p[i].length = my_strlen(av[i]);
        p[i].str = av[i];
        p[i].copy = my_strdup(av[i]);
        p[i].word_array = my_str_to_word_array(av[i]);
        i++;
    }
    p[i].str = NULL;
    return (p);
}
