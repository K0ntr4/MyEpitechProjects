/*
** EPITECH PROJECT, 2021
** BISTRO
** File description:
** desc
*/

#include <stdlib.h>

#include "my.h"
#include "header.h"

void init_str_arr(char **nbp, int res_len)
{
    nbp[0] = malloc(sizeof(char) * res_len);
    nbp[1] = malloc(sizeof(char) * res_len);
    nbp[2] = malloc(sizeof(char) * res_len);
    nbp[3] = malloc(sizeof(char) * (res_len + 2));
    nbp[5] = malloc(sizeof(char) * res_len);
    nbp[7] = malloc(sizeof(char) * 2);
    nbp[0][0] = '\0';
    nbp[3][0] = '\0';
}

char *free_str_arr(char **nbp, int neg)
{
    char *res;

    free(nbp[0]);
    free(nbp[1]);
    free(nbp[2]);
    free(nbp[5]);
    free(nbp[7]);
    res = malloc(sizeof(char) * my_strlen(nbp[3]) + 1);
    my_strcpy(res, nbp[3]);
    free(nbp[3]);
    free(nbp);
    return prepare_res(res, my_strlen(res), neg);
}

char *free_str_arr_mod(char **nbp, int neg)
{
    char *res;

    free(nbp[0]);
    free(nbp[1]);
    free(nbp[2]);
    free(nbp[3]);
    free(nbp[7]);
    res = malloc(sizeof(char) * my_strlen(nbp[5]) + 1);
    my_strcpy(res, nbp[5]);
    free(nbp[5]);
    free(nbp);
    return prepare_res(res, my_strlen(res), neg);
}

void norm_div_str(char *inp1, char *inp2)
{
    remove(1, inp2, '-');
    remove(1, inp1, '-');
    rem_zer(inp2);
}
