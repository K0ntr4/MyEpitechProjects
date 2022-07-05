/*
** EPITECH PROJECT, 2021
** output
** File description:
** outputs a string
*/
#include <unistd.h>

int my_strlen(char const *str);

void output_error(char c)
{
    write(2, &c, 1);
}

void output_error_str(char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        output_error(str[i]);
    }
}
