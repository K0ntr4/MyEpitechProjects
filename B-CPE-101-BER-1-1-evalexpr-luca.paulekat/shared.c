/*
** EPITECH PROJECT, 2021
** SHARED
** File description:
** shated functions
*/

#include <stdlib.h>

#include "my.h"
#include "header.h"

char *copy_res(char *res, int start, int len, int neg)
{
    char *new_res = NULL;
    int i = 0;

    len = len == 0 ? 1 : len;
    len = neg == 1 ? len + 1 : len;
    new_res = malloc(sizeof(char) * (len + 2));
    if (neg) {
        new_res[0] = '-';
        i++;
        start--;
    }
    for (; i < len; i++)
        new_res[i] = res[i + start];
    new_res[len] = '\0';
    free(res);
    return new_res;
}

int num_len(char *str)
{
    int counter = 0;
    int i = 0;
    int found = 0;

    while (str[i]) {
        if (1 <= to_i(str[i]) && to_i(str[i]) <= 9)
            found = 1;
        if (found && 0 <= to_i(str[i]) && to_i(str[i]) <= 9)
            counter++;
        i++;
    }
    return counter;
}

char *prepare_res(char *res, int res_len, int neg)
{
    int starting_point = 0;
    int res_actual_len = 0;
    int num_started = 0;

    for (int i = 0; i < res_len; i++) {
        if (num_started == 0 && res[i] != '0') {
            num_started = 1;
            starting_point = i;
        }
        if (num_started == 1)
            res_actual_len++;
    }
    return copy_res(res, starting_point, res_actual_len, neg);
}

char *norm(char *str, int neg)
{
    int i = 0;

    while (!(1 <= to_i(str[i]) && to_i(str[i]) <= 9))
        i++;
    return copy_res(str, i, num_len(str), neg);
}

int larger_number(char *inp1, char *inp2)
{
    int inp1_it = num_len(inp1) - 1;
    int inp2_it = num_len(inp2) - 1;
    int larger = inp1_it > inp2_it ? 1 : 0;

    replace(inp1, '-', '0');
    replace(inp2, '-', '0');
    larger = inp2_it > inp1_it ? 2 : larger;
    if (larger != 0)
        return larger;
    for (int i = 0; inp1[i] && inp2[i]; i++) {
        if (inp1[i] > inp2[i]) {
            return 1;
        } else if (inp1[i] < inp2[i]) {
            return 2;
        } else {
            larger = larger;
		}
    }
    return larger;
}
