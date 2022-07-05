/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include <stddef.h>
#include <stdlib.h>

#include "my.h"
#include "myls.h"

int print_ll(my_ls_l *copy)
{
    my_putstr(copy->rights);
    my_putstr(". ");
    my_put_nbr(copy->n_link);
    my_putchar(' ');
    my_putstr(copy->pw);
    my_putchar(' ');
    my_putstr(copy->gr);
    my_putchar(' ');
    my_put_nbr(copy->size);
    my_putchar(' ');
    write(1, copy->time + 4, \
        (my_strlen(copy->time) - 13));
    my_putchar(' ');
}

int print_l_res(my_ls_l **l)
{
    my_ls_l *copy = *l;
    to_start(&copy);

    while (copy) {
        if (copy->flag_l == 1) {
            print_ll(copy);
        }
        my_putstr(copy->folder);
        if (copy->flag_l == 1)
            my_putchar('\n');
        if (copy->flag_l != 1)
            my_putchar(' ');
        copy = copy->next;
    }
    my_putchar('\n');
    to_start(&copy);
    return 0;
}

void free_l(my_ls_l *l)
{
    if (!l)
        return;
    to_start(&l);
    while (l->next) {
        l = l->next;
        free(l->prev->folder);
        if (l->prev->flag_l == 1)
            free(l->prev->rights);
        free(l->prev);
    }
    free(l->folder);
    free(l);
}

int sort_list(my_ls_l **l , int(*c)(char const *, char const *))
{
    my_ls_l *tmp_next;
    my_ls_l *tmp_prev;
    int i = 0;
    int counter = 0;

    to_start(l);
    while (*l && (*l)->next) {
        if (c((*l)->folder, (*l)->next->folder) > 0) {
            tmp_next = (*l)->next->next;
            tmp_prev = (*l)->prev;
            (*l)->next->next = *l;
            (*l)->prev = (*l)->next;
            if (tmp_prev)
                tmp_prev->next = (*l)->prev;
            (*l)->prev->prev = tmp_prev;
            (*l)->next = tmp_next;
            if ((*l)->next)
                (*l)->next->prev = *l;
            counter++;
        } else {
            *l = (*l)->next;
        }
    }
    to_start(l);
    if (counter != 0)
        sort_list(l, c);
    else
        return (0);
    return (84);
}

my_ls_l *rotate_list(my_ls_l *l)
{
    my_ls_l *tmp = NULL;

    to_end(&l);
    for (int i = 0; l->prev != NULL; i++) {
        tmp = l->next;
        l->next = l->prev;
        l->prev = tmp;
        l = l->next;
    }
    l->prev = l->next;
    l->next = NULL;
    to_start(&l);
    return l;
}