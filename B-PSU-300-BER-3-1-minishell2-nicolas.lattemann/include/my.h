/*
** EPITECH PROJECT, 2021
** MY.H
** File description:
** desc
*/

#ifndef MY_H_
    #define MY_H_

    #if __has_include("local.h")
        #include "local.h"
    #endif

typedef struct linked_list {
    struct linked_list *next;
    struct linked_list *prev;
    void *item;
} list_t;

char *convert_base(char const *nbr, char const *base_from, char const *base_to);

short includes(char *str, char c);

char *itos(int nb);

int print_list(list_t **list);

void *peek(list_t *list);

void free_list(list_t *list);

int list_length(list_t *list);

void join(list_t **list1, list_t **list2);

int delete_item(list_t **list);

list_t *to_end(list_t **list);

list_t *to_start(list_t **list);

list_t *new_elem(void *item);

void append_item(list_t **list, void *item);

void *pop(list_t **list);

int arr_length(char **tab);

int my_chararrlen(char **arr);

void power(int nb, long *powered,  int *p);

int my_compute_power_rec(int nb, int p);

int calc_root(int nb);

int my_compute_square_root(int nb);

int my_find_prime_sup(int nb);

int my_getnbr_base(char const *str, char const *base);

int verify_validity(int digit, int *num, int *num_length);

void is_negative(char const *str, int iter, int *neg);

void add_digit(int digit, int *number, int neg);

int get_digit(char const *str, int i);

int my_getnbr(char const *str);

int my_intlen(int nb);

int my_isneg(int n);

int my_is_prime(int nb);

void *my_malloc(int size);

void my_putchar(char c);

int my_puterror(char const *str);

void my_put_float(float nb, int dec);

int my_put_nbr(int nb);

int my_putstr(char const *str);

unsigned int get_length(char *str);

char *my_revstr(char *str);

int my_showmem(char const *str, int size);

int my_showstr(char const *str);

int my_show_word_array(char **tab);

int my_sort_char_array(char **arr, int size);

int sort(int *arr, int size);

void my_sort_int_array(int *array, int size);

short is_low(char c);

short is_up(char c);

short is_dig(char c);

short is_val(char c);

char *my_strcapitalize(char *str);

char *my_strcat(char *str1, char *str2);

unsigned int get_length3(char const *str);

int my_strcmp(char const *s1, char const *s2);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

char *my_strjoin(char *str1, char *str2, short to_free);

int my_strlen(char const *str);

char *my_strlowcase(char *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strncpy(char *dest, char const *src, int n);

unsigned int get_length2(char const *str);

short check_substr(char *str, char const *to_find, unsigned int i);

char *my_strstr(char *str, char const *to_find);

char **my_str_to_word_array(char const *str);

char *my_strupcase(char *str);

void my_swap(int *a, int *b);

#endif
