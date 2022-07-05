/*
** EPITECH PROJECT, 2022
** Project
** File description:
** desc
*/
#include <stddef.h>
#include <stdlib.h>

void array_1d_to_2d(const int *array, size_t height, size_t width,
    int ***res)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int **new_a = malloc(sizeof(int *) * height);

    while (i < (int)height) {
        new_a[i] = malloc(sizeof(int ) * (int)width);
        while (j < (int)width) {
            new_a[i][j] = array[i + k];
            j++;
            k++;
        }
        k -= 1;
        j = 0;
        i++;
    }
    *res = new_a;
}

void array_2d_free(int **array, size_t height, size_t width)
{
    int i = 0;
    int j = 0;

    while (i < (int)height)
        free (array[i++]);
    free (array);
}
