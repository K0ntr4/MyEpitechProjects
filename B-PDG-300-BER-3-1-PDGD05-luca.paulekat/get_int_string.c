/*
** EPITECH PROJECT, 2025
** project
** File description:
** desc
*/
#include "string.h"

int to_int(const string_t *this)
{
    if (this == NULL)
        return 0;
    return my_getnbr(this->str);
}