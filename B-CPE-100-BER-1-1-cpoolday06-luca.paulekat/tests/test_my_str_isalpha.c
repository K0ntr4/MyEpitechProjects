/*
** EPITECH PROJECT, 2021
** test_my_str_isalpha.c
** File description:
** tests my_str_isalpha
*/
#include <criterion/criterion.h>

Test(my_str_isalpha , checks_if_str_is_alphabetical)
{
    cr_expect_geq(my_str_isalpha("Hey, How Are You? 42words."), 0);
}

Test(my_str_isalpha2 , checks_if_str_is_alphabetical2)
{
    cr_expect_geq(my_str_isalpha("HeyHowAreYou"), 1);
}
