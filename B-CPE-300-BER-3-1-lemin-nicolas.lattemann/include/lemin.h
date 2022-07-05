/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef B_CPE_300_BER_3_1_BSLEMIN_NICOLAS_LATTEMANN_BSLEMIN_H
    #define B_CPE_300_BER_3_1_BSLEMIN_NICOLAS_LATTEMANN_BSLEMIN_H
    #define DEFAULT_ROOM 0
    #define START_ROOM 1
    #define END_ROOM 2
    #define QUEUE_LEN 50
    #define KOWALSKI my_putstr("Kowalski, analysis.\n");

typedef struct room {
    char *name;
    int *coordinates;
    int special;
    int anted;
    int identifier;
    list_t *next;
} room_t;

room_t *create_link(char *name, int identifier);

room_t *connect_links(room_t *link1, room_t *link2, int test);

void print_link(room_t *link);

void print_data_of_connected_links(room_t *link);

char **read_input(void);

char **split_string(char *input, char split);

room_t *parse_input(char **str, int *n_room);

void show_input(const char **input);

int safety_checks(room_t *start, int n_room);

int comments_before_ants(char **str);

int comments_after_command(char **str, int j);

int validate_str(char **str);

void show_room(room_t *room, int visited[]);

room_t *returning_start_room(room_t **links);

void get_linking_rooms(room_t **links, char **tmp, int *n);

void fill_array(int arr[], int value, int len);

room_t *cast_ll(list_t *list);

void flush_queue(room_t *queue[], int room_nbr);

void init_arrs(int visited[], int trace[], room_t *queue[], int n_room);

void free_list_validation(list_t *list);

int at_end(list_t *linked_rooms, room_t *queue[], int n_room, int *end_room);

void start_nested(list_t **lk_rooms, room_t *queue[], room_t **node, int
n_room);

void iterate_and_mark_visited(int visited[], list_t **linked_rooms);

void fill_queue(room_t *node, room_t *queue[], int n_room, int visited[]);

#endif //B_CPE_300_BER_3_1_BSLEMIN_NICOLAS_LATTEMANN_BSLEMIN_H
