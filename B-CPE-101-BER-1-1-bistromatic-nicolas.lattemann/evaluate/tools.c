/*
** EPITECH PROJECT, 2021
** TOOLS
** File description:
** desc
*/

#include "header.h"

int to_i(char c)
{
    return (int)c - 48;
}

void fill(char *str, char character, int n)
{
    for (int i = 0; i < n; i++) {
        str[i] = character;
    }
}

int count(char *str, char c)
{
    int i = 0;
    int counter = 0;

    while (str[i]) {
        if (str[i] == c)
            counter++;
        i++;
    }
    return counter;
}

void replace(char *str, char c1, char c2)
{
    int i = 0;

    while (str[i]) {
        if (str[i] == c1)
            str[i] = c2;
        i++;
    }
}

void remove(int n, char *str, char c)
{
    int i = n;
    int counter = 0;

    if (str[i - 1] == c) {
        counter++;
        while (i < my_strlen(str)) {
            str[i - 1] = str[i];
            i++;
        }
        str[i - 1] = '\0';
    }
    if (counter != 0)
        remove(i + 1, str, c);
}
