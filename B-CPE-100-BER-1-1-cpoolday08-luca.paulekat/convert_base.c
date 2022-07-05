/*
** EPITECH PROJECT, 2021
** convert_base
** File description:
** converts a number from one base to another
*/
#include <stdlib.h>

extern int my_strlen(char const *str);
extern int my_getnbr(char const *str);
extern int my_compute_power_rec(int nb , int p);
extern char *my_revstr(char *str);
extern int digit_into_number(char nb);
extern int back_into_ascii(char nb);

int to_dec(char const *nbr, int bf)
{
    int l = my_strlen(nbr);
    int i = 0;
    int n = 0;
    int b = 0;

    while (i < l) {
        b = my_compute_power_rec(bf, l - i - 1);
        n += digit_into_number(nbr[i]) * b;
        b = 0;
        i++;
    }
    return (n);
}

char *mall(int dec, int bt, int nb)
{
    int counter = 0;
    char *out;
    int neg = 0;

    if (nb < 0)
        neg++;
    while (dec / bt > 0) {
        dec /= bt;
        counter++;
    }
    counter++;
    out = malloc(sizeof(char) * counter + 1 + neg);
    return (out);
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    int bf = my_getnbr(base_from);
    int bt = my_getnbr(base_to);
    int nb = my_getnbr(nbr);
    int dec = to_dec(nbr, bf);
    int i = 0;
    char *out = mall(dec, bt, nb);
    int l = my_strlen(nbr);

    if ((l == 1 && nb >= bf) || bf < 2 || bf > 36 || l == 0)
        return (NULL);
    while (dec / bt > 0) {
        out[i++] = back_into_ascii(dec % bt);
        dec /= bt;
    }
    out[i++] = back_into_ascii(dec % bt);
    if (nb < 0)
        out[i++] = '-';
    out[i] = '\0';
    my_revstr(out);
    return (out);
}
