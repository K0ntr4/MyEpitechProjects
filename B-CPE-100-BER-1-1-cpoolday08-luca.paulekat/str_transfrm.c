/*
** EPITECH PROJECT, 2021
** convert_base
** File description:
** converts a number from one base to another
*/
#include <stdlib.h>

int digit_into_number(char nb)
{
    int n = 0;

    if (nb > 64 && nb < 91) {
        n = nb - 55;
    } else if (nb > 48 && nb < 57) {
        n = nb - 48;
    } else {
        ;
    }
    return (n);
}

int back_into_ascii(char nb)
{
    int n = 0;

    if (nb > 9 && nb < 27) {
        n = nb + 55;
    } else if (nb < 10) {
        n = nb + 48;
    } else {
        ;
    }
    return (n);
}
