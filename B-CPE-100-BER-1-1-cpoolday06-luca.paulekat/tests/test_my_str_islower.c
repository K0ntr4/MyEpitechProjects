/*
** EPITECH PROJECT, 2021
** test_my_str_islower.c
** File description:
** tests my_str_islower
*/
#include <criterion/criterion.h>

Test(my_str_islower1, checks_if_str_is_lowercase1)
{
    cr_expect_geq(my_str_islower("hey, How Are You?"), 0);
}

Test(my_str_islower2, checks_if_str_is_lowercase2)
{
    cr_assert(my_str_islower("heyhowareyou") == 1);
}
