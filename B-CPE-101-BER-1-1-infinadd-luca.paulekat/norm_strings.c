/*
** EPITECH PROJECT, 2021
** norm_strings
** File description:
** appends zeros to norm given strings
*/
#include "include/my.h"

char *append_zero(char *str, int l)
{
    char *zeros = malloc(l + 1);
    int i = 0;

    while (i < l - my_strlen(str)) {
        zeros[i] = '0';
        i++;
    }
    zeros[i] = '\0';
    return (my_strcat(zeros, str));
}

void remove_neg(char *str)
{
    int i = 1;

    while (i < my_strlen(str)) {
        str[i - 1] = str[i];
        i++;
    }
    str[i - 1] = '\0';
    i = 1;
}

void check_zeros(char **str)
{
    if (my_strlen(str[1]) < my_strlen(str[2]))
        str[1] = append_zero(str[1], my_strlen(str[2]));
    else if (my_strlen(str[1]) > my_strlen(str[2]))
        str[2] = append_zero(str[2], my_strlen(str[1]));
}

int res_is_neg(char **str)
{
    if (str[1][0] == '-' && str[2][0] == '-') {
        remove_neg(str[1]);
        remove_neg(str[2]);
        return (3);
    }
    if (str[1][0] == '-' && str[2][0] != '-') {
        remove_neg(str[1]);
        return (2);
    }
    if (str[2][0] == '-' && str[1][0] != '-') {
        remove_neg(str[2]);
        return (1);
    }
    return (0);
}
