/*
** EPITECH PROJECT, 2022
** Project
** File description:
** desc
*/
#include <unistd.h>

int my_putstr(char *str)
{
    int length = 0;

    while (str[length] != '\0') {
        write(1, &str[length], 1);
        length += 1;
    }
    return (0);
}

int main(void)
{
    my_putstr("z\n");
    return 0;
}
