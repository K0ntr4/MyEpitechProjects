/*
** EPITECH PROJECT, 2021
** MY_PUTSTR
** File description:
** put string
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    int iter = 0;

    while (*(str + iter)) {
        write(2, (str + iter), 1);
        iter += 1;
    }
    return (0);
}
