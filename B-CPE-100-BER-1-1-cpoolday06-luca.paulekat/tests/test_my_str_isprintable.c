/*
** EPITECH PROJECT, 2021
** test_my_str_isprintable.c
** File description:
** tests my_str_isprintable
*/
#include <criterion/criterion.h>

Test(my_str_isprintable, checks_if_str_is_printable)
{
    cr_assert(my_str_isprintable("hey, How Are You? 42words") == 1);
}

Test(my_str_isprintable, checks_if_str_is_printable_true)
{
    cr_assert(my_str_isprintable("") == 1);
}

Test(my_str_isprintable, checks_if_str_is_printable_false)
{
    cr_assert(my_str_isprintable("\n") == 0);
}
