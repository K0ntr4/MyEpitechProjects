/*
** EPITECH PROJECT, 2025
** project
** File description:
** desc
*/
#include "string.h"

static void insertion_c(const char *str, size_t pos, char *new_str,
    string_t *this)
{
    int i = 0;
    int j = 0;

    while (i < (int)pos) {
        new_str[i] = this->str[i];
        i++;
    }
    while (j <= my_strlen(str)) {
        new_str[i + j] = str[j];
        j++;
    }
    while (str[i] != '\0') {
        new_str[i + j - 1] = this->str[i];
        i++;
    }
    new_str[i + j - 1] = '\0';
}

static void insertion_s(const string_t *str, size_t pos, char *new_str,
    string_t *this)
{
    int i = 0;
    int j = 0;

    while (i < (int)pos) {
        new_str[i] = this->str[i];
        i++;
    }
    while (j <= my_strlen(str->str)) {
        new_str[i + j] = str->str[j];
        j++;
    }
    while (i <= my_strlen(this->str)) {
        new_str[i + j - 1] = this->str[i];
        i++;
    }
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    int j = 0;
    char *new_str = NULL;

    if (this == NULL || str == NULL)
        return;
    if ((int)pos > my_strlen(this->str)) {
        this->append_c(this, str);
        return;
    }
    new_str = malloc(sizeof(char) * (my_strlen(str) +
        my_strlen(this->str) + 1));
    insertion_c(str, pos, new_str, this);
    free(this->str);
    this->str = new_str;
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    int i = 0;
    int j = 0;
    char *new_str = NULL;

    if (this == NULL || str == NULL)
        return;
    if ((int)pos > my_strlen(this->str)) {
        this->append_s(this, str);
        return;
    }
    new_str = malloc(sizeof(char) * (my_strlen(str->str) +
        my_strlen(this->str) + 1));
    insertion_s(str, pos, new_str, this);
    free(this->str);
    this->str = new_str;
}