/*
** EPITECH PROJECT, 2021
** INFINADD
** File description:
** desc
*/

#include <stdlib.h>

#include "my.h"
#include "header.h"

static void add(int i, char *res, int num)
{
    int added = ((int)res[i]) - 48 + num;

    if (added > 9) {
        res[i] = (added % 10) + 48;
        add(i - 1, res, added / 10);
    } else {
        res[i] = added + 48;
    }
}

static int neg_add(char *inp1, char *inp2)
{
    int neg1 = count(inp1, '-') % 2;
    int neg2 = count(inp2, '-') % 2;

    return (neg1 + neg2 == 2 ? 1 : 0);
}

char *local_infinadd(char *inp1, char *inp2)
{
    int inp1_len = my_strlen(inp1);
    int inp2_len = my_strlen(inp2);
    int res_len = (inp1_len > inp2_len ? inp1_len : inp2_len) + 1;
    char *res = malloc(sizeof(char) * (res_len + 1));
    int nbr1 = 0;
    int nbr2 = 0;
    int inp1_it = inp1_len - 1;
    int inp2_it = inp2_len - 1;
    int neg = neg_add(inp1, inp2);

    replace(inp1, '-', '0');
    replace(inp2, '-', '0');
    fill(res, '0', res_len);
    res[res_len] = '\0';
    for (int i = res_len - 1; i >= 0 && (inp1_it >= 0 || inp2_it >= 0); i--) {
        nbr1 = inp1_it >= 0 ? (int)inp1[inp1_it--] - 48 : 0;
        nbr2 = inp2_it >= 0 ? (int)inp2[inp2_it--] - 48 : 0;
        add(i, res, nbr1 + nbr2);
    }
    return prepare_res(res, res_len, neg);
}

char *infinadd(char *inp1, char *inp2)
{
    int neg1 = count(inp1, '-') % 2;
    int neg2 = count(inp2, '-') % 2;

    if (neg1 && !neg2) {
        remove(1, inp1, '-');
        return infinsub(inp2, inp1);
    }
    if (!neg1 && neg2) {
        remove(1, inp2, '-');
        return infinsub(inp1, inp2);
    }
    return local_infinadd(inp1, inp2);
}
