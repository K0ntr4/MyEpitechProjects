/*
** EPITECH PROJECT, 2021
** my_strdup
** File description:
** allocates memory and copies the string in it
*/
#include <stdlib.h>

extern int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int l = my_strlen(src);
    int i = 0;
    char *p;

    p = malloc(sizeof(char) * (l + 1));
    if (p == NULL)
        return (NULL);
    while (i < l) {
        p[i] = src[i];
        i++;
    }
    return (p);
}
