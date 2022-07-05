/*
** EPITECH PROJECT, 2022
** Project
** File description:
** desc
*/
#include <stdlib.h>
#include "../include/concat.h"

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0') {
        length += 1;
    }
    return (length);
}

void concat_strings(const char *str1, const char *str2, char **res)
{
    int i = 0;
    int j = 0;
    char *conc = malloc(sizeof(char) * (my_strlen(str1) +
        my_strlen(str2) + 1));

    if (conc == NULL)
        return;
    while (str1[i] != '\0') {
        conc[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0')
        conc[i++] = str2[j++];
    conc[i] = '\0';
    *res = conc;
}

void concat_struct(concat_t *str)
{
    int i = 0;
    int j = 0;
    char *conc = malloc(sizeof(char) * (my_strlen(str->str1) +
        my_strlen(str->str2) + 1));

    if (conc == NULL)
        return;
    while (str->str1[i] != '\0') {
        conc[i] = str->str1[i];
        i++;
    }
    while (str->str2[j] != '\0')
        conc[i++] = str->str2[j++];
    conc[i] = '\0';
    str->res = conc;
}
