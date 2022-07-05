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

int compare_precedence(char *op1, char *op2)
{
    short op1_pre = includes(DASH, op1[0]) ? 2 : 1;
    short op2_pre = includes(DASH, op2[0]) ? 2 : 1;

    if (op1_pre > op2_pre)
        return 1;
    else if (op1_pre == op2_pre)
        return 0;
    else
        return -1;
}
