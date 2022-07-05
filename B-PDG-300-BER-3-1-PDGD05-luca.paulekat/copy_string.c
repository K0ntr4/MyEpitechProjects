/*
** EPITECH PROJECT, 2025
** project
** File description:
** desc
*/
#include "string.h"

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    char *str = s;
    int value;
    int i = 0;

    if (this == NULL || pos > my_strlen(this->str))
        return -1;

    while (i < (int)n && this->str[(int)pos + i] != '\0') {
        s[i] = this->str[pos + i];
        i++;
    }
    if (i < (int)n && this->str[(int)pos + i] == '\0') {
        s[i] = '\0';
        i++;
    }
    return (i);
}

const char *c_str(const string_t *this)
{
    if (this == NULL)
        return NULL;
    return (this->str);
}

int empty(const string_t *this)
{
    if (this->str == NULL || my_strlen(this->str) == 0)
        return 1;
    return 0;
}