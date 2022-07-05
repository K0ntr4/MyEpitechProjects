/*
** EPITECH PROJECT, 2021
** TEST
** File description:
** desc
*/

#include <criterion/criterion.h>

#include "my.h"
#include "header.h"

Test(infinadd, 1)
{
    char *str1 = my_strdup("435439435845843984358439");
    char *str2 = my_strdup("45359766785665822182412343254343435433339459569");

    cr_expect_str_eq("45359766785665822182412778693779281277323818008", infinadd(str1, str2));
}

Test(infinadd, 2)
{
    char *str1 = my_strdup("-807965");
    char *str2 = my_strdup("-34532");

    cr_expect_str_eq("-842497", infinadd(str1, str2));
}

Test(infinadd, 3)
{
    char *str1 = my_strdup("-876435");
    char *str2 = my_strdup("987143265");

    cr_expect_str_eq("986266830", infinadd(str1, str2));
}

Test(infinadd, 4)
{
    char *str1 = my_strdup("0");
    char *str2 = my_strdup("0");

    cr_expect_str_eq("0", infinadd(str1, str2));
}

Test(infinadd, 5)
{
    char *str1 = my_strdup("--876435");
    char *str2 = my_strdup("--987143265");

    cr_expect_str_eq("988019700", infinadd(str1, str2));
}

Test(infinadd, 6)
{
    char *str1 = my_strdup("-55");
    char *str2 = my_strdup("5");

    cr_expect_str_eq("-50", infinadd(str1, str2));
}

Test(infinadd, 7)
{
    char *str1 = my_strdup("-55");
    char *str2 = my_strdup("60");

    cr_expect_str_eq("5", infinadd(str1, str2));
}

Test(infinadd, 8)
{
    char *str1 = my_strdup("5");
    char *str2 = my_strdup("-55");

    cr_expect_str_eq("-50", infinadd(str1, str2));
}

Test(infinadd, 9)
{
    char *str1 = my_strdup("60");
    char *str2 = my_strdup("-55");

    cr_expect_str_eq("5", infinadd(str1, str2));
}

Test(infinadd, 10)
{
    char *str1 = my_strdup("0");
    char *str2 = my_strdup("-1");

    cr_expect_str_eq("-1", infinadd(str1, str2));
}
