/*
** EPITECH PROJECT, 2021
** TEST
** File description:
** desc
*/

#include <criterion/criterion.h>

#include "my.h"
#include "header.h"

Test(infinmul, 1)
{
    char *str1 = my_strdup("435439435845843984358439");
    char *str2 = my_strdup("45359766785665822182412343254343435433339459569");

    cr_expect_str_eq("19751431259249377577477260257991869607323389072856925074540645444452791", infinmul(str1, str2));
}

Test(infinmul, 2)
{
    char *str1 = my_strdup("-807965");
    char *str2 = my_strdup("-34532");

    cr_expect_str_eq("27900647380", infinmul(str1, str2));
}

Test(infinmul, 3)
{
    char *str1 = my_strdup("-876435");
    char *str2 = my_strdup("987143265");

    cr_expect_str_eq("-865166907460275", infinmul(str1, str2));
}

Test(infinmul, 4)
{
    char *str1 = my_strdup("0");
    char *str2 = my_strdup("0");

    cr_expect_str_eq("0", infinmul(str1, str2));
}

Test(infinmul, 5)
{
    char *str1 = my_strdup("-876435");
    char *str2 = my_strdup("-987143265");

    cr_expect_str_eq("865166907460275", infinmul(str1, str2));
}

Test(infinmul, 6)
{
    char *str1 = my_strdup("-55");
    char *str2 = my_strdup("5");

    cr_expect_str_eq("-275", infinmul(str1, str2));
}

Test(infinmul, 7)
{
    char *str1 = my_strdup("-55");
    char *str2 = my_strdup("60");

    cr_expect_str_eq("-3300", infinmul(str1, str2));
}

Test(infinmul, 8)
{
    char *str1 = my_strdup("5");
    char *str2 = my_strdup("-55");

    cr_expect_str_eq("-275", infinmul(str1, str2));
}

Test(infinmul, 9)
{
    char *str1 = my_strdup("60");
    char *str2 = my_strdup("-55");

    cr_expect_str_eq("-3300", infinmul(str1, str2));
}

Test(infinmul, 10)
{
    char *str1 = my_strdup("0");
    char *str2 = my_strdup("-1");

    cr_expect_str_eq("0", infinmul(str1, str2));
}
