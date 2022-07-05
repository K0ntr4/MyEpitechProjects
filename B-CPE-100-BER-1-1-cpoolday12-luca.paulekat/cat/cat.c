/*
** EPITECH PROJECT, 2021
** cat.c
** File description:
** performs the same task as cat
*/
#include "../include/my.h"
#include <stdio.h>
#include <fcntl.h>

void output_error_str(char *str);

void reset_buffer(char *b, int length)
{
    for (int i = 0; i < length; i++)
        b[i] = 0;
}

int read_f(char *buf, int n, char **f, int rd)
{
    int fd;

    for (int i = 1; i < n; i++) {
        reset_buffer(buf, 10000);
        fd = open(f[i], O_RDONLY);
        if (fd <= 0)
            return (84);
        rd = read(fd, buf, 10000);
        if (rd < 0)
            return (84);
        my_putstr(buf);
        close(fd);
    }
    return (0);
}

int cat(int argc, char **argv)
{

    char buf[10000];
    int rd = 0;
    int counter = 0;

    if (argc == 1) {
        reset_buffer(buf, 10000);
        rd = read(0, buf, 10000);
        if (rd < 0)
            return (84);
        my_putstr(buf);
        counter++;
        if (counter < 10000)
            cat(argc, argv);
    } else
        return (read_f(buf, argc, argv, rd));
}
