/*
** EPITECH PROJECT, 2021
** TEST
** File description:
** desc
*/

#include <criterion/criterion.h>

#include "my.h"
#include "header.h"

Test(infinmod, 1)
{
    char *str1 = my_strdup("435439435845843984358439");
    char *str2 = my_strdup("45359766785665822182412343254343435433339459569");

    cr_expect_str_eq("435439435845843984358439", infinmod(str1, str2));
}

Test(infinmod, 2)
{
    char *str1 = my_strdup("-807965");
    char *str2 = my_strdup("-34532");

    cr_expect_str_eq("-13729", infinmod(str1, str2));
}

Test(infinmod, 3)
{
    char *str1 = my_strdup("876435");
    char *str2 = my_strdup("987143265");

    cr_expect_str_eq("277455", infinmod(str2, str1));
}

Test(infinmod, 4)
{
    char *str1 = my_strdup("0");
    char *str2 = my_strdup("10");

    cr_expect_str_eq("0", infinmod(str1, str2));
}

Test(infinmod, 5)
{
    char *str1 = my_strdup("876435");
    char *str2 = my_strdup("987143265");

    cr_expect_str_eq("876435", infinmod(str1, str2));
}

Test(infinmod, 6)
{
    char *str1 = my_strdup("55");
    char *str2 = my_strdup("5");

    cr_expect_str_eq("0", infinmod(str1, str2));
}

Test(infinmod, 7)
{
    char *str1 = my_strdup("55");
    char *str2 = my_strdup("60");

    cr_expect_str_eq("55", infinmod(str1, str2));
}

Test(infinmod, 8)
{
    char *str1 = my_strdup("-100");
    char *str2 = my_strdup("-6");

    cr_expect_str_eq("-4", infinmod(str1, str2));
}

Test(infinmod, 9)
{
    char *str1 = my_strdup("-99");
    char *str2 = my_strdup("5");

    cr_expect_str_eq("-4", infinmod(str1, str2));
}

Test(infinmod, 10)
{
    char *str1 = my_strdup("0");
    char *str2 = my_strdup("1");

    cr_expect_str_eq("0", infinmod(str1, str2));
}

Test(infinmod, 11)
{
    char *str1 = my_strdup("43543943584");
    char *str2 = my_strdup("45359766785665");

    cr_expect_str_eq("30521514721", infinmod(str2, str1));
}
