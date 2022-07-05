/*
** EPITECH PROJECT, 2021
** concat_params
** File description:
** concats arguments into one string
*/
#include <stdlib.h>
int check_a(char const *str, int i);

int get_array_len(char const *str)
{
    int i = 0;
    int counter = 0;

    while (str[i] != '\0') {
        if (check_a(str, i) == 1 && check_a(str, i - 1) != 1)
            counter++;
        i++;
    }
    counter++;
    return (counter);
}
