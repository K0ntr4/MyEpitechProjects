/*
** EPITECH PROJECT, 2025
** project
** File description:
** desc
*/
#include "string.h"

int my_putstr(char *str)
{
    int length = 0;

    while (str[length] != '\0'){
        write(1, &str[length], 1);
        length += 1;
    }
    return (0);
}

void print(const string_t *this)
{
    if (this == NULL)
        return;
    my_putstr(this->str);
}