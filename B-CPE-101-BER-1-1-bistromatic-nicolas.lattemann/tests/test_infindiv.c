/*
** EPITECH PROJECT, 2021
** TEST
** File description:
** desc
*/

#include <criterion/criterion.h>

#include "my.h"
#include "header.h"

Test(infindiv, 1)
{
    char *str1 = my_strdup("435439435845843984358439");
    char *str2 = my_strdup("45359766785665822182412343254343435433339459569");

    cr_expect_str_eq("0", infindiv(str1, str2));
}

Test(infindiv, 2)
{
    char *str1 = my_strdup("-807965");
    char *str2 = my_strdup("-34532");

    cr_expect_str_eq("23", infindiv(str1, str2));
}

Test(infindiv, 3)
{
    char *str1 = my_strdup("-876435");
    char *str2 = my_strdup("987143265");

    cr_expect_str_eq("0", infindiv(str1, str2));
}

Test(infindiv, 4)
{
    char *str1 = my_strdup("0");
    char *str2 = my_strdup("10");

    cr_expect_str_eq("0", infindiv(str1, str2));
}

Test(infindiv, 5)
{
    char *str1 = my_strdup("-876435");
    char *str2 = my_strdup("-987143265");

    cr_expect_str_eq("0", infindiv(str1, str2));
}

Test(infindiv, 6)
{
    char *str1 = my_strdup("-55");
    char *str2 = my_strdup("5");

    cr_expect_str_eq("-11", infindiv(str1, str2));
}

Test(infindiv, 7)
{
    char *str1 = my_strdup("-55");
    char *str2 = my_strdup("60");

    cr_expect_str_eq("0", infindiv(str1, str2));
}

Test(infindiv, 8)
{
    char *str1 = my_strdup("5");
    char *str2 = my_strdup("-55");

    cr_expect_str_eq("0", infindiv(str1, str2));
}

Test(infindiv, 9)
{
    char *str1 = my_strdup("60");
    char *str2 = my_strdup("-55");

    cr_expect_str_eq("-1", infindiv(str1, str2));
}

Test(infindiv, 10)
{
    char *str1 = my_strdup("0");
    char *str2 = my_strdup("-1");

    cr_expect_str_eq("0", infindiv(str1, str2));
}

Test(infindiv, 11)
{
    char *str1 = my_strdup("435439435845843984358439");
    char *str2 = my_strdup("45359766785665822182412343254");

    cr_expect_str_eq("104170", infindiv(str2, str1));
}
