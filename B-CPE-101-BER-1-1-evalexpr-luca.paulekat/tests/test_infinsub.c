/*
** EPITECH PROJECT, 2021
** INFINSUB
** File description:
** test
*/

#include <criterion/criterion.h>

#include "my.h"
#include "header.h"

Test(infinsub, 1)
{
    char *str1 = my_strdup("435439435845843984358439");
    char *str2 = my_strdup("453597667856658221824123");

    cr_expect_str_eq("-18158232010814237465684", infinsub(str1, str2));
}

Test(infinsub, 2)
{
    char *str1 = my_strdup("-807965");
    char *str2 = my_strdup("34532");

    cr_expect_str_eq("-842497", infinsub(str1, str2));
}

Test(infinsub, 3)
{
    char *str1 = my_strdup("9");
    char *str2 = my_strdup("4");

    cr_expect_str_eq("5", infinsub(str1, str2));
}

Test(infinsub, 4)
{
    char *str1 = my_strdup("--876435");
    char *str2 = my_strdup("--987143265");

    cr_expect_str_eq("-986266830", infinsub(str1, str2));
}

Test(infinsub, 5)
{
    char *str1 = my_strdup("-9");
    char *str2 = my_strdup("-4");

    cr_expect_str_eq("-5", infinsub(str1, str2));
}

Test(infinsub, 6)
{
    char *str1 = my_strdup("807965");
    char *str2 = my_strdup("-34532");

    cr_expect_str_eq("842497", infinsub(str1, str2));
}

Test(infinsub, 7)
{
    char *str1 = my_strdup("-55");
    char *str2 = my_strdup("5");

    cr_expect_str_eq("-60", infinsub(str1, str2));
}

Test(infinsub, 8)
{
    char *str1 = my_strdup("-55");
    char *str2 = my_strdup("60");

    cr_expect_str_eq("-115", infinsub(str1, str2));
}

Test(infinsub, 9)
{
    char *str1 = my_strdup("5");
    char *str2 = my_strdup("-55");

    cr_expect_str_eq("60", infinsub(str1, str2));
}

Test(infinsub, 10)
{
    char *str1 = my_strdup("60");
    char *str2 = my_strdup("-55");

    cr_expect_str_eq("115", infinsub(str1, str2));
}
