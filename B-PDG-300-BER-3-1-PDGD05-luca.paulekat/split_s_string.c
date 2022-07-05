/*
** EPITECH PROJECT, 2025
** project
** File description:
** desc
*/
#include "string.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    if (src[i] == '\0')
        dest[i] = '\0';
    return (dest);
}

static string_t **finish_arr(char **arr, string_t **string_arr, int j)
{
    free(arr);
    string_arr[j] = NULL;
    return string_arr;
}

string_t **split_s(const string_t *this, char separator)
{
    string_t **string_arr = NULL;
    char **arr = split_c(this, separator);
    int i = 0;
    int j = 0;

    if (arr == NULL)
        return NULL;
    while (arr[i])
        i++;
    string_arr = malloc(sizeof(string_t *) * (i + 1));
    if (string_arr == NULL)
        return NULL;
    while (arr[j]) {
        string_arr[j] = string_create(arr[j]);
        free(arr[j]);
        j++;
    }
    return finish_arr(arr, string_arr, j);
}