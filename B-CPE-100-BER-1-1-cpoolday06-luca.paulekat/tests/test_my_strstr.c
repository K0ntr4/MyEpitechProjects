/*
** EPITECH PROJECT, 2021
** test_my_strstr.c
** File description:
** tests my_strstr
*/
#include <criterion/criterion.h>

Test(my_strstr , locates_string_inside_string)
{
    char s1[60] = "hey, test 42WORds\0";
    char *p = s1 + 5;

    cr_assert_str_eq(my_strstr("hey, test 42WORds\0", "test\0"), p);
}
