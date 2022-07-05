/*
** EPITECH PROJECT, 2025
** project
** File description:
** desc
*/
#include "string.h"

void join_c(string_t *this, char delim, const char * const * array)
{
    char *new_str = NULL;
    int i = 0;
    int size = 0;
    char *str;

    if (array == NULL)
        return;
    i = 0;
    if (this->str != NULL)
        free(this->str);
    this->str = my_strdup("");
    while (array[i] != NULL) {
        str = append_char((char *)array[i], delim);
        append_c(this, str);
        free(str);
        i++;
    }
    this->str[my_strlen(this->str) - 1] = '\0';
    free((void *)array);
}

void join_s(string_t *this, char delim, const string_t * const * array)
{
    char *new_str = NULL;
    int i = 0;
    int size = 0;
    char *str;

    if (array == NULL)
        return;
    i = 0;
    if (this->str != NULL)
        free(this->str);
    this->str = my_strdup("");
    while (array[i] != NULL) {
        str = append_char((char *)array[i]->str, delim);
        append_c(this, str);
        free(str);
        free((void *)array[i]);
        i++;
    }
    this->str[my_strlen(this->str) - 1] = '\0';
    free((void *)array);
}