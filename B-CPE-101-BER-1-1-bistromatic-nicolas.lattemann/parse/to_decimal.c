/*
** EPITECH PROJECT, 2021
** MY_GETNBR_BASE
** File description:
** desc
*/

#include <stddef.h>
#include <stdlib.h>

#include "my.h"
#include "header.h"
#include "parser.h"

static char *loop(char *base, char *str)
{
    char *buffer = "";
    char *ch_i = NULL;
    char *nbr = my_strdup("");

    for (int i = 0; i < my_strlen(str); i++) {
        buffer = infinmul(nbr, base);
        free(nbr);
        ch_i = itos(65 <= str[i] && str[i] <= 70 ? str[i] - 55 : str[i] - 48);
        nbr = infinadd(buffer, ch_i);
        free(ch_i);
        free(buffer);
    }
    return nbr;
}

static char *get_nbr(char *str, char *base)
{
    char *nbr = NULL;
    int neg = str[0] == '-';
    char *neg_fac = my_strdup("-1");
    char *buffer = "";

    if (neg)
        str[0] = '0';
    nbr = loop(base, str);
    if (neg) {
        buffer = infinmul(nbr, neg_fac);
        free(nbr);
        nbr = buffer;
    }
    free(neg_fac);
    free(base);
    return nbr;
}

char *to_decimal(char *str, int base)
{
    char *result = NULL;

    if (base == 10) {
        result = my_strdup(str);
        free(str);
        return result;
    }
    result = get_nbr(str, itos(base));
    free(str);
    return result;
}
