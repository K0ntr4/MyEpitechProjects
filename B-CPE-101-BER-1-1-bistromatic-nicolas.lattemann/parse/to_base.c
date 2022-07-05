/*
** EPITECH PROJECT, 2021
** CONVERT_BASE
** File description:
** desc
*/

#include <stddef.h>
#include <stdlib.h>

#include "my.h"
#include "header.h"
#include "parser.h"

static void free_up_to_four(void *one, void *two, void *three, void *four)
{
    if (one)
        free(one);
    if (two)
        free(two);
    if (three)
        free(three);
    if (four)
        free(four);
}

static char to_char(char *str, char *base)
{
    char *rem = infinmod(str, base);
    int n = my_getnbr(rem);

    free(rem);
    return n < 10 ? n + 48 : n + 55;
}

static char *process(char *str, char *base)
{
    char *nbr = malloc(sizeof(char) * my_strlen(str) * 4);
    size_t i = 0;
    short neg = str[0] == '-';
    char *buffer = NULL;

    remove(1, str, '-');
    for (; my_strcmp(str, "0\0"); i++) {
        nbr[i] = to_char(str, base);
        buffer = infindiv(str, base);
        free(str);
        str = buffer;
    }
    if (neg)
        nbr[i++] = '-';
    nbr[i] = '\0';
    nbr = my_revstr(nbr);
    free_up_to_four(NULL, str, base, NULL);
    return resize(nbr, i);
}

char *to_base(char *nbr, int base)
{
    if (base == 10 || (nbr[0] == '0'))
        return my_strdup(nbr);
    return process(my_strdup(nbr), itos(base));
}
