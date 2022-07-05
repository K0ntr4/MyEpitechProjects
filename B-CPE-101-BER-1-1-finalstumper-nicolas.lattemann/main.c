/*
** EPITECH PROJECT, 2021
** FInal Stumper
** File description:
** desc
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "header.h"

int get_dimensions(char *buff, int *x, int *y)
{
    for (int i = 0; buff[i]; i++) {
        *y = buff[i] == '\n' ?  *y + 1 : *y;
        *x = *y == 0 ? *x + 1 : *x;
    }
    return 0;
}

int free_arr(char **arr, int n)
{
    for (int i = 0; i < n; i++)
            free(arr[i]);
    free(arr);
    return 0;
}

int check_ret(int len, int offset, int buff_len)
{
    if (len < 0)
        return 84;
    if (offset - 1 > 4095 || buff_len == 0) {
        my_putstr("none\n");
        return 0;
    }
    return 1;
}

int main(void)
{
    char buff[5000];
    int offset = 0;
    int len = 0;
    int x = 0;
    int y = 0;
    char **arr = NULL;

    while ((len = read(0, buff + offset, 5000 - offset)) > 0)
        offset += len;
    buff[offset] = '\0';
    if (my_strlen(buff) == 0 || len < 0 || offset - 1 > 4095)
        return check_ret(len, offset, my_strlen(buff));
    get_dimensions(buff, &x, &y);
    arr = to_twodarray(buff, x, y);
    if (arr == NULL)
        return 84;
    if (rush3(arr, x, y) == 42)
        my_putstr("none\n");
    free_arr(arr, y);
    return 0;
}
