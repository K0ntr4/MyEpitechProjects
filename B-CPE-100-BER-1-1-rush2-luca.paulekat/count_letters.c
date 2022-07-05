/*
** EPITECH PROJECT, 2021
** RUSH2
** File description:
** desc
*/

#include "my.h"
#include "header.h"

char normalize(char c)
{
    return 65 <= c && c <= 90 ? c + 32 : c;
}

static int count_letter(int c, char *string, letter *data_arr)
{
    int i = 0;
    int str_l = letters_in_str(string);
    float frequency = 0;

    if (data_arr[c].counted)
        return 0;
    while (string[i]) {
        if (normalize(string[i]) == c + 97) {
            data_arr[c].occurences++;
        }
        i++;
    }
    data_arr[c].counted = 1;
    frequency = ((float)data_arr[c].occurences / (float)str_l) * 100;
    data_arr[c].frequency = frequency;
    return 0;
}

int count_letters(char *string, letter *data_array)
{
    for (int i = 0; i < 26; i++) {
        count_letter(i, string, data_array);
    }
    return 0;
}
