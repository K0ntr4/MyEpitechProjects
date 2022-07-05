/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** desc
*/

#include "mylist.h"
#include "my.h"

void sw_first_two(linked_list_t *l_a)
{
    char *content = malloc(my_strlen(l_a->data) * sizeof(char) + 1);

    to_start(&l_a);
    if (l_a->next != NULL) {
        my_strcpy(content, l_a->data);
        free (l_a->data);
        l_a->data = l_a->next->data;
        l_a->next->data = content;
    }
}

void handle_placeholder(linked_list_t **l_a, linked_list_t *l_b)
{
    if (l_b && l_b->next && my_strcmp(l_b->data, " ") == 0) {
        l_b = l_b->next;
        free(l_b->prev->data);
        free(l_b->prev);
        l_b->prev = NULL;
    }
    if (!((*l_a)->next)) {
        (*l_a)->next = new_elem(my_strdup(" "));
        (*l_a)->next->prev = *l_a;
    }
}

linked_list_t *move_to_first_of_list(linked_list_t **l_a, linked_list_t *l_b, \
    char *print, linked_list_t *print_list)
{
    to_start(l_a);
    remove_placeholder_l(l_a);
    to_start(l_a);
    to_start(&l_b);
    handle_placeholder(l_a, l_b);
    if (*l_a && l_b) {
        *l_a = (*l_a)->next;
        l_b->prev = (*l_a)->prev;
        (*l_a)->prev = NULL;
        l_b->prev->next = l_b;
        l_b = l_b->prev;
    } else {
        return l_b;
    }
    to_start(&l_b);
    if (my_strcmp(l_b->next->data, " ") == 0)
        remove_placeholder_l(&l_b);
    to_start(&l_b);
    print_op("p\0", print, print_list);
    return l_b;
}

void move_to_end(linked_list_t *l_a, char *print, linked_list_t *print_list)
{
    linked_list_t *tmp;

    remove_placeholder_l(&l_a);
    to_start(&l_a);
    l_a = l_a->next;
    l_a->prev->next = NULL;
    tmp = l_a->prev;
    l_a->prev = NULL;
    to_end(&l_a);
    l_a->next = tmp;
    l_a->next->prev = l_a;
    to_start(&l_a);
    print_op("r\0", print, print_list);
}

void rotate_to_begin(linked_list_t *l_a, char *print, linked_list_t *print_list)
{
    linked_list_t *n = NULL;

    to_end(&l_a);
    n = l_a;
    l_a = l_a->prev;
    l_a->next = NULL;
    to_start(&l_a);
    l_a->prev = n;
    l_a->prev->prev = NULL;
    l_a->prev->next = l_a;
    print_op("rr\0", print, print_list);
    to_start(&l_a);
}
