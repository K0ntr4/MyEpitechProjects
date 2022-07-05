/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** desc
*/

#include "mylist.h"
#include "my.h"

linked_list_t *last_move(linked_list_t **l, linked_list_t *l2, \
    char *print, linked_list_t *print_list)
{
    char *rev_print = print == "a" ? "b" : "a";

    l2 = remove_placeholder_l(&l2);
    to_start(&l2);
    while (l2 && l2->next) {
        rotate_to_begin(l2, print, print_list);
        *l = move_to_first_of_list(&l2, *l, rev_print, print_list);
    }
    *l = move_to_first_of_list(&l2, *l, rev_print, print_list);
    return l2;
}

void print_op(char *pre, char *print, linked_list_t *print_list)
{
    to_end(&print_list);
    char *str = print_list->data;
    int length = my_strlen(print_list->data);
    char *new_str;

    if (length >= 500) {
        write(1, print_list->data, length);
        free(print_list->data);
        print_list->data = malloc(sizeof(char) * 510);
        str = print_list->data;
        str[0] = '\0';
    }
    my_strcat(print_list->data, pre);
    my_strcat(print_list->data, print);
    my_strcat(print_list->data, " ");
}

void print_print_list(linked_list_t *print_list)
{
    to_start(&print_list);
    int length = my_strlen(print_list->data);

    write(1, print_list->data, length - 1);
    free(print_list->data);
    my_putstr("\n");
}
