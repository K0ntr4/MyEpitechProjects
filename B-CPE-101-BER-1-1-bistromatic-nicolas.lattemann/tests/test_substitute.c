/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include <criterion/criterion.h>

#include "my.h"
#include "header.h"
#include "parser.h"

Test(substitute, 1)
{
    char *sub_num = my_strdup("ABCDEFGHIJ");
    char *sub_ope = my_strdup("KLMNOPQ");
    char *expression = my_strdup("KBMCLOD");
   
    substitute(&expression, sub_num, sub_ope, 1);
    cr_expect_str_eq("(1+2)*3", expression);
}

Test(substitute, 2)
{
    char *sub_num = my_strdup("0A@!;ie& ]");
    char *sub_ope = my_strdup("()+-*/%");
    char *expression = my_strdup("-(e@-(;*!@))");
   
    substitute(&expression, sub_num, sub_ope, 1);
    cr_expect_str_eq("-(62-(4*32))", expression);
}

Test(substitute, 3)
{
    char *sub_num = my_strdup("ABCDEFGHIJKLMNOP");
    char *sub_ope = my_strdup("()+-*/%");
    char *expression = my_strdup("P*P");

    substitute(&expression, sub_num, sub_ope, 1);
    cr_expect_str_eq("F*F", expression);
}
