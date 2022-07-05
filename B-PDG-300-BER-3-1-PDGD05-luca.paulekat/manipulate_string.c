/*
** EPITECH PROJECT, 2025
** project
** File description:
** desc
*/
#include "string.h"

int my_strlen(char const *str)
{
    int length = 0;
    char arr = *str;
    char l;

    while (str[length] != '\0'){
        length += 1;
    }
    return (length);
}

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
    p[i] = '\0';
    return (p);
}

void append_s(string_t *this, const string_t *ap)
{
    int l = my_strlen(this->str);
    int i = my_strlen(ap->str);
    int j = 0;
    char *new_str = malloc(sizeof(char) * l + i + 1);

    i = 0;
    while (j <= l) {
        new_str[j] = this->str[j];
        j++;
    }
    while (ap->str[i] != '\0') {
        new_str[l + i] = ap->str[i];
        i++;
    }
    new_str[l + i] = '\0';
    if (this->str != NULL)
        free(this->str);
    this->str = new_str;
}

void append_c(string_t *this, const char *ap)
{
    int l = my_strlen(this->str);
    int i = my_strlen(ap);
    int j = 0;
    char *new_str = malloc(sizeof(char) * l + i + 1);

    i = 0;
    while (j <= l) {
        new_str[j] = this->str[j];
        j++;
    }
    while (ap[i] != '\0') {
        new_str[l + i] = ap[i];
        i++;
    }
    new_str[l + i] = '\0';
    if (this->str != NULL)
        free(this->str);
    this->str = new_str;
}

void clear(string_t *this)
{
    if (this->str != NULL)
        free(this->str);
    this->str = my_strdup("");
}