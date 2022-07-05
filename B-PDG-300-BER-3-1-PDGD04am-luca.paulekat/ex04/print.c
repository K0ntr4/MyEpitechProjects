/*
** EPITECH PROJECT, 2022
** Project
** File description:
** desc
*/
#include "../include/print.h"
#include <unistd.h>
#include <stdlib.h>

void print_normal(const char *str)
{
    int length = 0;

    while (str[length] != '\0') {
        write(1, &str[length], 1);
        length += 1;
    }
    write(1, "\n", 1);
}

void print_reverse(const char *str)
{
    int i = 0;
    int l = 0;
    char tmp;
    char *cpy;

    while (str[l] != '\0')
        l += 1;
    cpy = malloc(sizeof(char) * l + 1);
    while ((str[i] != '\0') && (i < l / 2)) {
        tmp = str[l - 1 - i];
        cpy[l - 1 - i] = str[i];
        cpy[i] = tmp;
        i++;
    }
    cpy[l] = '\0';
    print_normal(cpy);
    free(cpy);
}

void print_upper(const char *str)
{
    int i = 0;
    char *cpy;
    int l = 0;

    while (str[l] != '\0')
        l += 1;
    cpy = malloc(sizeof(char) * l + 1);
    while (i < l) {
        if (str[i] >= 97 && str[i] <= 122)
            cpy[i] = str[i] - 32;
        else
            cpy[i] = str[i];
        i++;
    }
    cpy[l] = '\0';
    print_normal(cpy);
    free(cpy);
}

void print_42(const char *str)
{
    print_normal("42");
}

void do_action(action_t action, const char *str)
{
    void (* fx[4]) (const char *) = { &print_normal,
        &print_reverse, &print_upper, &print_42 };

    (*fx[action])(str);
}
