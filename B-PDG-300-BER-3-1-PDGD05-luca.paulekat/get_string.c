/*
** EPITECH PROJECT, 2025
** project
** File description:
** desc
*/
#include "string.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int dif = 0;
    int l1 = my_strlen(s1);
    int l2 = my_strlen(s2);

    while ((i < l2 || i < l1)) {
        dif += s1[i] - s2[i];
        i++;
        if (dif < 0)
            return (-1);
        if (dif > 0)
            return (1);
    }
    return (0);
}

char get_string_at(const string_t *this, size_t pos)
{
    char *str = NULL;

    if (this == NULL)
        return -1;
    str = this->str;
    for (int i = 0; str[i] != '\0' && i <= pos; i++) {
        if (i == pos)
            return str[i];
    }
    return -1;
}

int length(const string_t *this)
{
    if (this == NULL)
        return -1;
    return my_strlen(this->str);
}

int compare_c(const string_t *this, const char *str)
{
    if (this == NULL)
        return -1;
    return my_strcmp(this->str, str);
}

int compare_s(const string_t *this, const string_t *str)
{
    if (this == NULL || str == NULL)
        return -1;
    return my_strcmp(this->str, str->str);
}