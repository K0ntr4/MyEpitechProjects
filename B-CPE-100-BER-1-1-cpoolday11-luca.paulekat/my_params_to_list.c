/*
** EPITECH PROJECT, 2021
** my_params_to_list
** File description:
** creates a new list from the command line arguments
*/
#include "include/mylist.h"

linked_list_t *insert_into_list(linked_list_t *list, char *data)
{
    linked_list_t *l = NULL;

    l = malloc(sizeof(linked_list_t));
    l->data = data;
    l->next = list;
    list = l;
    return (l);
}

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *nl = NULL;
    char *data;

    for (int i = 0; i < ac; i++) {
        data = av[i];
        nl = insert_into_list(nl, data);
    }
    return (nl);
}
