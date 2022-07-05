/*
** EPITECH PROJECT, 2022
** Project
** File description:
** desc
*/
#include <stddef.h>
#include <stdlib.h>

size_t resize (int *array, int elem, size_t nmemb)
{
    int found = 0;
    int j = 0;
    int n = 0;

    while (j < (int)(nmemb)) {
        printf("%d%d\n", elem, array[j]);
        if (array[j] == elem && found == 1) {
            printf("now2");
            n += 1;
            array[j] = array[j + 1];
        } else if (array[j] == elem && found == 0) {
            printf("now");
            found = 1;
        } else {
            ;
        }
        j++;
    }
    printf("%ld\n%d\n", nmemb, n);
    return nmemb - n;
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    int elem;

    for (int i = 0; i <= (int)(nmemb); i++) {
        elem = array[i];
        nmemb = resize(array, elem, nmemb);
    }
    return nmemb;
}
