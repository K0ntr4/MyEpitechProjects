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

my_ls_l *to_end(my_ls_l **l)
{
    while (*l && (*l)->next)
        *l = (*l)->next;
    return *l;
}

my_ls_l *to_start(my_ls_l **l)
{
    while (*l && (*l)->prev)
        *l = (*l)->prev;
    return *l;
}

my_ls_l *new_elem(char *folder, int *flags)
{
    my_ls_l *elem = malloc(sizeof(my_ls_l));

    if (!elem)
        return NULL;
    elem->next = NULL;
    elem->prev = NULL;
    elem->flag_l = flags[0];
    elem->flag_R = flags[1];
    elem->flag_t = flags[2];
    elem->flag_d = flags[3];
    elem->flag_r = flags[4];
    elem->folder = my_strdup(folder);
    return elem;
}

void append_item(my_ls_l **l, char *folder, int *flags)
{
    my_ls_l *elem = new_elem(folder, flags);

    if (!elem)
        return;
    if (!(*l)) {
        *l = elem;
        return;
    }
    to_end(l);
    elem->prev = *l;
    (*l)->next = elem;
}

void *pop(my_ls_l **l)
{
    char *folder = NULL;
    my_ls_l *prev = NULL;

    to_end(l);
    folder = (*l)->folder;
    if ((*l)->prev)
        (*l)->prev->next = NULL;
    prev = (*l)->prev;
    free((*l));
    *l = prev;
    return folder;
}
