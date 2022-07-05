/*
** EPITECH PROJECT, 2021
** my_list_size
** File description:
** returns the number of elements in a list
*/

#include "include/mylist.h"
#include "my.h"

int my_list_size(linked_list_t *begin)
{
    int counter = 0;

    to_start(&begin);
    for (int i = 0; begin != NULL; i++) {
        counter++;
        begin = begin->next;
    }
    return (counter);
}
