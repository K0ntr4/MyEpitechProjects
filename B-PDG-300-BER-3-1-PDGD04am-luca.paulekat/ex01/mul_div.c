/*
** EPITECH PROJECT, 2022
** Project
** File description:
** desc
*/

void mul_div_long(int a, int b, int *mul, int *div)
{
    *mul = a * b;
    if (b == 0) {
        *div = 42;
        return;
    }
    *div = a / b;
}

void mul_div_short(int *a, int *b)
{
    int x = *a;

    *a = x * (*b);
    if (*b == 0) {
        *b = 42;
        return;
    }
    *b = x / *b;
}