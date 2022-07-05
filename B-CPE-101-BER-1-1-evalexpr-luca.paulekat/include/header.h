/*
** EPITECH PROJECT, 2021
** HEADER
** File description:
** desc
*/

#ifndef HEADER_H_
    #define HEADER_H_

int my_strlen(char const *str);

int to_i(char c);

void fill(char *str, char character, int n);

int count(char *str, char c);

void replace(char *str, char c1, char c2);

void remove(int n, char *str, char c);

char *copy_res(char *res, int start, int len, int neg);

char *prepare_res(char *res, int res_len, int neg);

char *infinadd(char *inp1, char *inp2);

char *local_infinadd(char *inp1, char *inp2);

char *infinsub(char *inp1, char *inp2);

char *local_infinsub(char *inp1, char *inp2, int neg, int larger);

char *infinmul(char *inp1, char *inp2);

char *local_infinmul(char *inp1, char *inp2, int neg);

char *infindiv(char *inp1, char *inp2);

char *local_infindiv(char *inp1, char *inp2, int neg);

int num_len(char *str);

char *norm(char *str, int neg);

int larger_number(char *inp1, char *inp2);

#endif
