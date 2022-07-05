/*
** EPITECH PROJECT, 2025
** project
** File description:
** desc
*/
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    int i = (int)pos;
    int n = 0;
    int p;

    if (this == NULL || str == NULL)
        return -1;
    if (my_strlen(this->str) < (int)pos || pos < 0 || my_strlen(this->str) <
        my_strlen(str->str))
        return -1;
    while (this->str[i] != '\0') {
        if (this->str[i] == str->str[n] && str->str[n] != '\0')
            n++;
        else if (str->str[n] == 0)
            return i - n;
        else
            ;
        i++;
    }
    return -1;
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    int i = (int)pos;
    int n = 0;
    int p;

    if (this == NULL || str == NULL)
        return -1;
    if (my_strlen(this->str) < (int)pos || pos < 0 || my_strlen(this->str) <
        my_strlen(str))
        return -1;
    while (this->str[i] != '\0') {
        if (this->str[i] == str[n] && str[n] != '\0')
            n++;
        else if (str[n] == 0)
            return i - n;
        else
            ;
        i++;
    }
    return -1;
}