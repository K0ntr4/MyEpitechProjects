/*
** EPITECH PROJECT, 2021
** Final Stumper
** File description:
** desc
*/

#include <stddef.h>
#include "my.h"
#include "header.h"

int put_result(char *name, int x, int y, int l)
{
    my_putchar('[');
    my_putstr(name);
    my_putchar(']');
    my_putchar(' ');
    my_put_nbr(x);
    my_putchar(' ');
    my_put_nbr(y);
    if (l)
        my_putchar('\n');
    return 0;
}

int test_corners(char **arr, int x, int y, char *corner)
{
    int cond1 = corner[0] == arr[0][0];
    int cond2 = corner[1] == arr[0][x - 1];
    int cond3 = corner[2] == arr[y - 1][0];
    int cond4 = corner[3] == arr[y - 1][x - 1];

    return cond1 && cond2 && cond3 && cond4;
}

int predict(char **arr, int x, int y)
{
    if (arr[0][0] == 'B') {
        put_result("rush1-3", x, y, 0);
        my_putstr(" || ");
        put_result("rush1-4", x, y, 0);
        my_putstr(" || ");
        put_result("rush1-5", x, y, 1);
        return 0;
    }
    if (test_corners(arr, x, y, "AACC"))
        return put_result("rush1-3", x, y, 1);
    if (test_corners(arr, x, y, "ACAC"))
        return put_result("rush1-4", x, y, 1);
    if (test_corners(arr, x, y, "ACCA"))
        return put_result("rush1-5", x, y, 1);
    return 42;
}

int includes(char *str, char c)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}

int rush3(char **arr, int x, int y)
{
    if (validate(arr, x, y) == 84)
        return 42;
    x = x;
    if (arr[0][0] == 'o')
        put_result("rush1-1", x, y, 1);
    else if (includes("/\\*", arr[0][0]))
        put_result("rush1-2", x, y, 1);
    else
        return predict(arr, x, y);
    return 0;
}
