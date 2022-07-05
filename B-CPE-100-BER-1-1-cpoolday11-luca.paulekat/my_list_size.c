/*
** EPITECH PROJECT, 2021
** my_list_size
** File description:
** returns the number of elements in a list
*/

#include "include/mylist.h"

int my_list_size(linked_list_t const *begin)
{
    int counter = 0;

    for (int i = 0; begin != NULL; i++) {
        counter++;
        begin = begin->next;
    }
    return (counter);
}
