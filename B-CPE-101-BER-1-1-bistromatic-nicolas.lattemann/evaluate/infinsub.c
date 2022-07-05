/*
** EPITECH PROJECT, 2021
** INFINSUB
** File description:
** desc
*/

#include <stdlib.h>

#include "my.h"
#include "header.h"

static void subtract(int i, char *res, int num)
{
    num = num + to_i(res[i]);
    if (num < 0) {
        res[i] = (10 + num) + 48;
        res[i - 1] = to_i(res[i - 1]) - 1 + 48;
    } else {
        res[i] = num + 48;
    }
}

char *local_infinsub(char *inp1, char *inp2, int neg, int larger)
{
    int inp1_len = my_strlen(inp1);
    int inp2_len = my_strlen(inp2);
    int res_len = (inp1_len > inp2_len ? inp1_len : inp2_len);
    char *res = malloc(sizeof(char) * (res_len + 1));
    int nbr1 = 0;
    int nbr2 = 0;
    int inp1_it = inp1_len - 1;
    int inp2_it = inp2_len - 1;

    replace(inp1, '-', '0');
    replace(inp2, '-', '0');
    fill(res, '0', res_len);
    res[res_len] = '\0';
    for (int i = res_len - 1; i >= 0 && (inp1_it >= 0 || inp2_it >= 0); i--) {
        nbr1 = inp1_it >= 0 ? (int)inp1[inp1_it--] - 48 : 0;
        nbr2 = inp2_it >= 0 ? (int)inp2[inp2_it--] - 48 : 0;
        subtract(i, res, larger == 2 ? nbr2 - nbr1 : nbr1 - nbr2);
    }
    return prepare_res(res, res_len, neg);
}

char *infinsub(char *inp1, char *inp2)
{
    int neg1 = count(inp1, '-') % 2;
    int neg2 = count(inp2, '-') % 2;
    char *cp1 = my_strdup(inp1);
    char *cp2 = my_strdup(inp2);
    int larger = larger_number(cp1, cp2);
    free(cp1);
    free(cp2);
    int is_neg = (larger == 2 && neg1 == 0) || (larger == 1 && neg1 == 1);

    if (neg1 && !neg2)
        return local_infinadd(norm(inp1, 1), norm(inp2, 1));
    else if (!neg1 && neg2)
        return local_infinadd(inp1, norm(inp2, 0));
    else
        return local_infinsub(inp1, inp2, is_neg, larger);
}
