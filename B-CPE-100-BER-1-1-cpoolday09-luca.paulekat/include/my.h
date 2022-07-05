/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** contains the prototypes of all the functions in libmy
*/

#ifndef my_h_
    #define my_h_

    #include <unistd.h>
    #include <stddef.h>
    #include <stdlib.h>

int loop(int j, char const *str, char **p, int *i);
int get_array_len(char const *str);
char *mallocing_p(char * const *argv);
int check_lowcase(int i, char *str);
int check_upcase(int i, char *str);
int inc_n(long n, char *str, int x);
int check_neg_numbers(char const *str);
int check_non_int(char const *str);
int get_square_root(int nb);
int n_characters(char const *str, int i);
int check_a2(char const *str, int i);
int check_a(char const *str, int i);
int output(int o, int nb);
extern int my_strlen(char const *str);
char *my_revstr(char *str);
int my_putstr(char const *str);
int my_isneg(int n);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_is_prime(int nb);
int my_getnbr(char const *str);
int my_find_prime_sup(int nb);
int my_compute_square_root(int nb);
int my_compute_power_rec(int nb , int p);
char *my_strcat(char *dest , char const *src);
char *my_strcapitalize(char *str);
void my_sort_int_array(int *array , int size);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
int my_strcmp(char const *s1 , char const *s2);
char *my_strcpy(char *dest , char const *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest , char const *src, int nb);
int my_strncmp(char const *s1 , char const *s2, int n);
char *my_strncpy(char *dest , char const *src, int n);
char *my_strstr(char *str , char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
int my_show_word_array(char * const *tab);

#endif
