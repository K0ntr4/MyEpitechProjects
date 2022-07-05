/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** desc
*/
#include "my.h"
#include "myls.h"

int validate_flags(char *str)
{
    int valid = 0;

    for (int i = 0; str[i] && valid == 0; i++) {
        valid = 84;
        if (valid == 84)
            valid = str[i] == '-' ? 0 : 84;
        if (valid == 84)
            valid = str[i] == 'l' ? 0 : 84;
        if (valid == 84)
            valid = str[i] == 'R' ? 0 : 84;
        if (valid == 84)
            valid = str[i] == 't' ? 0 : 84;
        if (valid == 84)
            valid = str[i] == 'd' ? 0 : 84;
        if (valid == 84)
            valid = str[i] == 'r' ? 0 : 84;
    }
    return (valid);
}

int *get_flags(char *str, int *flags)
{
    if (validate_flags(str) == 84) {
        flags[0] = 2;
        return flags;
    }
    if (includes(str, 'l') > 0)
        flags[0] = 1;
    if (includes(str, 'R') > 0)
        flags[1] = 1;
    if (includes(str, 't') > 0)
        flags[2] = 1;
    if (includes(str, 'd') > 0)
        flags[3] = 1;
    if (includes(str, 'r') > 0)
        flags[4] = 1;
    return flags;
}
