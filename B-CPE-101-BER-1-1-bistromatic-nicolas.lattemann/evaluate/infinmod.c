/*
** EPITECH PROJECT, 2021
** INFINMOD
** File description:
** desc
*/

#include <stdlib.h>

#include "my.h"
#include "header.h"

void last_mod(char **nbp, int inp1_len, int *count)
{
    if (nbp[2][0] == '-' && count[0] == inp1_len)
        my_strcpy(nbp[5], nbp[1]);
}

static char *my_mod(char *nb, char *inp2, int counter, int started)
{
    int l1 = my_strlen(nb);
    int l2 = my_strlen(inp2);
    char *res;
    char *out;

    if (l2 > l1 || (l2 == l1 && my_strcmp(nb, inp2) < 0)) {
        free(nb);
        res = malloc(sizeof(char) * 2);
        res[0] = counter + 48;
        res[1] = '\0';
        return (res);
    }
    counter++;
    out = infinsub(nb, inp2);
    if (started != 0)
        free(nb);
    started++;
    return (my_mod(out, inp2, counter, started));
}

void manage_mod(char **nbp, char *inp2, char *inp1)
{
    nbp[4] = my_mod(nbp[0], inp2, 0, 0);
    my_strcat(nbp[3], nbp[4]);
    free(nbp[5]);
    nbp[6] = infinmul(inp2, nbp[4]);
    free(nbp[4]);
    nbp[5] = infinsub(nbp[0], nbp[6]);
    free(nbp[6]);
    if (nbp[5][0] != '0') {
        my_strcpy(nbp[0], nbp[5]);
    } else {
        free(nbp[0]);
        nbp[0] = malloc(sizeof(inp1));
        nbp[0][0] = '\0';
    }
}

char *local_infinmod(char *inp1, char *inp2, int neg)
{
    int inp1_len = my_strlen(inp1);
    int inp2_len = my_strlen(inp2);
    int res_len = (inp1_len > inp2_len ? inp1_len : inp2_len) + 2;
    char **nbp = malloc(sizeof(char *) * 8);
    int count[3] = {0, 0, 0};

    init_str_arr(nbp, res_len);
    while (count[0] <= inp1_len) {
        free(nbp[2]);
        nbp[2] = infinsub(nbp[0], inp2);
        if (nbp[2][0] == '-') {
            count[0] = manage_remainder(nbp, count, inp1, inp2);
        } else {
            manage_mod(nbp, inp2, inp1);
            count[2]++;
            count[1] = 0;
        }
    last_mod(nbp, inp1_len, count);
    }
    return free_str_arr_mod(nbp, neg);
}

char *infinmod(char *inp1, char *inp2)
{
    int neg1 = count(inp1, '-') % 2;
    int neg2 = count(inp2, '-') % 2;
    int l1;
    int l2;

    norm_div_str(inp1, inp2);
    l1 = my_strlen(inp1);
    l2 = my_strlen(inp2);
    if (inp2[0] == '\0') {
        my_puterror(ERROR_MSG);
        exit (84);
    }
    if ((l1 == l2 && my_strcmp(inp1, inp2) < 0) || l2 > l1)
        return my_strdup(inp1);
    if ((neg1 && !neg2) || (!neg1 && neg2))
        return local_infinmod(inp1, inp2, 1);
    else if (neg1 && neg2)
        return local_infinmod(inp1, inp2, 1);
    else
        return local_infinmod(inp1, inp2, 0);
}
