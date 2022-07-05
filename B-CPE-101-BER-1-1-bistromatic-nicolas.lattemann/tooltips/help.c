/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include "my.h"
#include "header.h"

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("./calc base operators size_read\n");
    my_putstr("\nDESCRIPTION\n");
    my_putstr("- base: all the symbols of the base\n");
    my_putstr("- operators: the symbols for the \
parentheses and the 5 operators\n");
    my_putstr("- size_read: number of characters to be read\n");
    return EXIT_USAGE;
}

int help_short(char *str)
{
    my_putstr("Usage: ");
    my_putstr(str);
    my_putstr(" base ops\"()+-*/%\" exp_len\n");
    return EXIT_USAGE;
}
