/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include <stddef.h>
#include <stdlib.h>

#include "my.h"
#include "header.h"
#include "parser.h"

static int check_neg(char **num, int j, int is_neg)
{
    if (is_neg % 2 == 1) {
        num[0][j] = '-';
        return j + 1;
    }
    return j;
}

static char *get_number(char **p_str)
{
    short found = 0;
    char *str = *p_str;
    int str_len = my_strlen(str);
    char *num = malloc(sizeof(char) * (str_len + 3));
    int is_neg = 0;
    int j = 0;
    int i = 0;

    for (; str[i] && !(found && !is_alpha_num(str[i])); i++) {
        is_neg += str[i] == '-' ? 1 : 0;
        if (found == 0 && is_alpha_num(str[i])) {
            found = 1;
            j = check_neg(&num, j, is_neg);
        }
        if (found && is_alpha_num(str[i]))
            num[j++] = str[i];
    }
    *p_str = &str[i];
    num[j] = '\0';
    return resize(num, j);
}

char *get_next_item(char **p_expr, int base)
{
    char *str = NULL;
    int par_i = is_par(*p_expr);

    if (par_i != 0) {
        str = malloc(sizeof(char) * 2);
        str[0] = !is_neg_par(*p_expr) ? *p_expr[0] : '$';
        str[1] = '\0';
        *p_expr = !is_neg_par(*p_expr) ? &p_expr[0][1] : &p_expr[0][par_i + 1];
        return str;
    }
    if (!includes("%*-+/(#", p_expr[0][-1]) && includes(OPER, *p_expr[0])) {
        str = malloc(sizeof(char) * 2);
        str[0] = *p_expr[0];
        str[1] = '\0';
        *p_expr = &p_expr[0][1];
        return str;
    } else
        return to_decimal(get_number(p_expr), base);
}

void insert_neg_par(list_t **ast_stack, list_t **operators, char *item)
{
    item[0] = '(';
    append_item(operators, my_strdup("*"));
    append_item(ast_stack, new_ast_node(my_strdup("-1"), NULL, NULL));
    append_item(operators, item);
}
