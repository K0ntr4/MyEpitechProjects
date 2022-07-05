/*
** EPITECH PROJECT, 2021
** HEADER
** File description:
** desc
*/

#ifndef HEADER_H_
    #define HEADER_H_
    #define EXIT_USAGE 84
    #define EXIT_BASE 84
    #define EXIT_SIZE_NEG 84
    #define EXIT_MALLOC 84
    #define EXIT_READ 84
    #define EXIT_OPS 84
    #define EXIT_SYNTAX 84
    #define SYNTAX_ERROR_MSG "syntax error"
    #define ERROR_MSG "error"

char *bistromatic(char **argv, char *expression);

int help(void);

int help_short(char *str);

char *eval_expr(char *expr, int base);

void rem_zer(char *str);

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

void norm_div_str(char *inp1, char *inp2);

char *local_infindiv(char *inp1, char *inp2, int neg);

char *infinmod(char *inp1, char *inp2);

int manage_remainder(char **nbp, int *count, char *inp1, char *inp2);

void init_str_arr(char **nbp, int res_len);

char *free_str_arr_mod(char **nbp, int neg);

char *free_str_arr(char **nbp, int neg);

int num_len(char *str);

char *norm(char *str, int neg);

int larger_number(char *inp1, char *inp2);

int substitute(char **p_expr, char *sub_num, char *sub_oper, int rev);

int validate_expression(char *expression);

char *add_delimiters(char *expression);

int is_alpha_num(char c);

void syntax_exit(void);

int validate_base(char *base, char *oper);

int closing_parentheses(char *expr, int i);

int opening_parentheses(char *expr, int i);

int dashes(char *expr, int i);

int dots(char *expr, int i);

char *to_decimal(char *str, int base);

char *to_base(char *nbr, int base);

#endif
