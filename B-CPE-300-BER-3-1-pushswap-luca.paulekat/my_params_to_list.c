/*
** EPITECH PROJECT, 2021
** my_params_to_list
** File description:
** creates a new list from the command line arguments
*/
#include "mylist.h"
#include "my.h"

linked_list_t *insert_into_list(linked_list_t *list, char *data)
{
    linked_list_t *l = NULL;

    l = malloc(sizeof(linked_list_t));
    l->data = data;
    l->next = list;
    l->prev = list;
    list = l;
    return (l);
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *nl = NULL;
    char *data;

    for (int i = 1; i < ac; i++) {
        data = my_strdup(av[i]);
        append_item(&nl, data);
    }
    return (nl);
}
