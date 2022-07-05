/*
** EPITECH PROJECT, 2022
** Project
** File description:
** desc
*/
#include <stddef.h>

void sort_int_array(int *array, size_t nmemb)
{
    int tmp;
    int c = 0;

    for (int i = 0; i < (int)nmemb - 1; i++) {
        if (array[i] > array[i + 1]) {
            tmp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = tmp;
            c += 1;
        }
    }
    if (c != 0)
        sort_int_array(array, nmemb);
}

/*void sort_array(void *array, size_t nmemb, size_t size, 
    int(* compar)(const void *, const void *))
{
    void *tmp;
    int c = 0;

    for (int i = 0; i < (int)nmemb * (int)size; i += (int)size) {
        if (compar (array + i, array + i + (int)size) < 0) {
            tmp = array + i;
            (char *)array + i = array + i + (int)size;
            (char *)array + i + (int)size = tmp;
            c += 1;
        }
        i += 1;
    }
    if (c != 0)
        sort_array(array, nmemb, size, compar);
}
*/