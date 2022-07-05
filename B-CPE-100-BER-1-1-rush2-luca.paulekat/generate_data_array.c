/*
** EPITECH PROJECT, 2021
** RUSH2
** File description:
** desc
*/

#include "my.h"
#include "header.h"
#include <stdlib.h>

void show_letter(letter letter, char c)
{
    if (c)
        my_putchar(c);
    else
        my_putchar(letter.character);
    my_putchar(':');
    my_put_nbr(letter.occurences);
    my_putchar(' ');
    my_putchar('(');
    my_put_float(letter.frequency, 2);
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');
}

void show_data_array(letter *data_array)
{
    for (int i = 0; i < 26; i++) {
        show_letter(data_array[i], 0);
    }
}

void show_results(char argc, char **argv, letter *data_array)
{
    char c = 0;

    for (int i = 2; i < argc; i++) {
        c = argv[i][0];
        show_letter(data_array[normalize(c) - 97], c);
    }
}

struct letter *generate_data_array(void)
{
    letter *data_array = malloc(sizeof(letter) * (26 + 1));

    for (int i = 0; i < 26; i++) {
        data_array[i].character = i + 97;
        data_array[i].occurences = 0;
        data_array[i].frequency = 0;
        data_array[i].counted = 0;
    }
    data_array[26].character = '\0';
    data_array[26].occurences = 0;
    data_array[26].frequency = 0;
    return data_array;
}
