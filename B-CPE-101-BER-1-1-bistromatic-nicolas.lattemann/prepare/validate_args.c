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

int validate_base(char *base, char *oper)
{
    for (int i = 0; base[i]; i++) {
        if (includes(base, base[i]) > 1)
            syntax_exit();
        if (includes(oper, base[i]))
            syntax_exit();
    }
    return 0;
}
