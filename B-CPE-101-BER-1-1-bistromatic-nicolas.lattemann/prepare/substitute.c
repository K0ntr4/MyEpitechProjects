/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include <stdlib.h>

#include "header.h"
#include "my.h"
#include "parser.h"

static char get_num_sub(char c, char *sub_num, int rev)
{
    int sub_len = my_strlen(sub_num);

    for (int i = 0; rev && sub_num[i]; i++) {
        if (sub_num[i] == c) {
            return i < 10 ? i + 48 : i + 55;
        }
    }
    if (!rev && (c <= '9' ? c - 48 : c - 55) < sub_len)
        return sub_num[c <= '9' ? c - 48 : c - 55];
    return 0;
}

static char get_oper_sub(char c, char *sub_oper, int rev)
{
    char *oper = "()+-*/%";

    for (int i = 0; rev && sub_oper[i]; i++) {
        if (sub_oper[i] == c)
            return oper[i];
    }
    if (!rev && c == oper[3])
        return sub_oper[3];
    return 0;
}

int substitute(char **p_expr, char *sub_num, char *sub_oper, int rev)
{
    char sub = 0;

    for (int i = 0; p_expr[0][i]; i++) {
        sub = get_oper_sub(p_expr[0][i], sub_oper, rev);
        if (sub) {
            p_expr[0][i] = sub;
            continue;
        }
        sub = get_num_sub(p_expr[0][i], sub_num, rev);
        if (sub) {
            p_expr[0][i] = sub;
            continue;
        }
        my_putstr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    return 0;
}
