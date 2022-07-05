/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** contains the prototypes of all the functions in libmy
*/

#ifndef my_list_
    #define my_list_

typedef struct linked_list {
    void *data;
    int nb;
    struct linked_list *next;
    struct linked_list *prev;
} linked_list_t;
linked_list_t *my_params_to_list(int ac, char * const *av);
linked_list_t *insert_into_list(linked_list_t *list, char *data);
void sw_first_two(linked_list_t *l_a);
void my_rev_list(linked_list_t ** begin);
void my_print_list(linked_list_t **l);
linked_list_t *move_to_first_of_list(linked_list_t **l_a, linked_list_t *l_b, \
    char *print, linked_list_t *print_list);
void rotate_to_begin(linked_list_t *l_a, char *print, \
    linked_list_t *print_list);
int print_l(linked_list_t **l);
void *peek(linked_list_t *l);
void free_l(linked_list_t *l);
linked_list_t *to_start(linked_list_t **l);
linked_list_t *to_end(linked_list_t **l);
linked_list_t *new_elem(void *item);
void append_item(linked_list_t **l, void *item);
void *pop(linked_list_t **l);
linked_list_t *quicksort_list(linked_list_t **l, linked_list_t **l2, \
    int *x, linked_list_t *print_list);
linked_list_t *move_to_end_of_list(linked_list_t **l_a, linked_list_t *l_b, \
    char print);
int my_list_size(linked_list_t *begin);
linked_list_t *remove_placeholder_l(linked_list_t **l);
linked_list_t *last_move(linked_list_t **l, linked_list_t *l2, \
    char *print, linked_list_t *print_list);
void print_op(char *pre, char *print, linked_list_t *print_list);
int check_list(linked_list_t *l, int i);
void move_x_0(linked_list_t **l, linked_list_t **l2, \
    int *n, linked_list_t *print_list);
char *get_print(int called);
linked_list_t *recurse_qs(linked_list_t **l, linked_list_t **l2, \
    int *n, linked_list_t *print_list);
void move_to_end(linked_list_t *l_a, char *print, linked_list_t *print_list);
void print_print_list(linked_list_t *print_list);
int my_putstr_fast(char const *str);
linked_list_t *to_unsorted(linked_list_t *l);

#endif
