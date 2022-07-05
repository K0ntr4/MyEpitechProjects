/*
** EPITECH PROJECT, 2021
** my_swap
** File description:
** swaps the content of two integers
*/

void my_swap(int *a, int *b)
{
    int one = *a;
    int two = *b;

    *a = two;
    *b = one;
}
