/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <lemin.h>
#include <malloc.h>

room_t *create_link(char *name, int identifier)
{
    room_t *link = malloc(sizeof(room_t));

    link->name = name;
    link->next = NULL;
    link->identifier = identifier;
    link->anted = 0;
    return link;
}

int check_in_links(room_t *link1, room_t *link2)
{
    list_t *links = link1->next;

    to_start(&links);
    while (links != NULL) {
        if (link2->identifier == ((room_t *) (links->item))->identifier)
            return 1;
        else
            links = links->next;
    }
    return 0;
}

room_t *connect_links(room_t *link1, room_t *link2, int test)
{
    if (check_in_links(link1, link2) != 0)
        return NULL;
    if (link1->next)
        append_item(&(link1->next), link2);
    else
        link1->next = new_elem(link2);
    if (test == 0)
        connect_links(link2, link1, 1);
    return link2;
}

void print_link(room_t *link)
{
    my_putstr(link->name);
    my_putchar('\n');
}

void print_data_of_connected_links(room_t *link)
{
    list_t *connected_links = link->next;

    to_start(&connected_links);
    while (connected_links) {
        my_putstr(((room_t *) (connected_links->item))->name);
        connected_links = connected_links->next;
        if (connected_links)
            my_putchar(' ');
    }
    connected_links = link->next;
    to_start(&connected_links);
    while (connected_links) {
        my_putchar('\n');
        print_data_of_connected_links((room_t *) (connected_links->item));
        connected_links = connected_links->next;
    }
}
