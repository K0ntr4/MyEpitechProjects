/*
** EPITECH PROJECT, 2022
** Project
** File description:
** desc
*/
#include <stddef.h>

extern void sort_int_array(int *array, size_t nmemb);
extern size_t uniq_int_array(int *array, size_t nmemb);

void disp_int_array(const int *array, size_t nmemb)
{
    for (int i = 0; i < (int)nmemb; i++) {
        printf("%d\n", array[i]);
    }
}

void main(void) {
    int array [16] = {10, 1, 24, 3, 47, 5, 5, 2, 8, 9, 2, 2, 2, 2, 2, 3};
    size_t size;

    size = uniq_int_array(array, 16);
    //sort_int_array(array, (size_t)10);
    disp_int_array(array, size);
}