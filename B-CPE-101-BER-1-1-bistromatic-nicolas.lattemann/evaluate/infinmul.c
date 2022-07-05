/*
** EPITECH PROJECT, 2021
** INFINMUL
** File description:
** desc
*/

#include <stdlib.h>

#include "my.h"
#include "header.h"

char *add_together(char *res, char *added_together)
{
    char *new = infinadd(res, added_together);

    free(added_together);
    return (new);
}

static void mul(int nbr, int n, char *res)
{
    if (res[n] + nbr > 57) {
        nbr = (res[n] - 48) + nbr;
        res[n] = nbr % 10 + 48;
        res[n - 1] = nbr / 10 + 48;
    } else {
        res[n] += nbr;
    }
}

char *local_infinmul(char *inp1, char *inp2, int neg)
{
    int inp1_len = my_strlen(inp1);
    int inp2_len = my_strlen(inp2);
    int res_len = (inp1_len + inp2_len) + 1;
    char *res = malloc(sizeof(char) * res_len);
    char *added_together = my_strdup("0");
    int nbr = 0;
    int k = 0;

    res[res_len - 1] = '\0';
    for (int j = inp2_len - 1; j >= 0; j--) {
        fill(res, '0', res_len - 1);
        for (int i = 1; i <= inp1_len; i++) {
            nbr = (inp1[inp1_len - i] - 48) * (inp2[j] - 48);
            mul(nbr, ((res_len - 1) - i) - k, res);
        }
        k++;
        added_together = add_together(res, added_together);
    }
    free(res);
    return prepare_res(added_together, res_len, neg);
}

char *infinmul(char *inp1, char *inp2)
{
    int neg1 = count(inp1, '-') % 2;
    int neg2 = count(inp2, '-') % 2;
    remove(1, inp2, '-');
    remove(1, inp1, '-');
    rem_zer(inp1);
    rem_zer(inp2);
    char *if_zero;

    if (inp2[0] == '\0' || inp1[0] == '\0') {
        if_zero = my_strdup("0");
        return (if_zero);
    }
    if ((neg1 && !neg2) || (!neg1 && neg2)) {
        return local_infinmul(inp1, inp2, 1);
    }
    return local_infinmul(inp1, inp2, 0);
}
