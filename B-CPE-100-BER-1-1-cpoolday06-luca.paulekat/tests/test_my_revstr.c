/*
** EPITECH PROJECT, 2021
** test_my_strncpy.c
** File description:
** tests my_strncpy
*/
#include <criterion/criterion.h>

Test(my_revstr , reverses_str)
{
    char str[5] = "test";

    my_revstr(str);
    cr_assert_str_eq(str , "tset");
}
