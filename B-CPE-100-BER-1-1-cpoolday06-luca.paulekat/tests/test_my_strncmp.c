/*
** EPITECH PROJECT, 2021
** test_my_strncmp.c
** File description:
** tests my_strncpy
*/
#include <criterion/criterion.h>

Test(my_strncmp , compares_n_characters_of_two_strings)
{
    cr_assert(my_strncmp("test2", "test ", 5) == 18);
}

Test(my_strncmp2 , compares_n_characters_of_two_strings2)
{
    cr_assert(my_strncmp("test ", "test2", 5) == -18);
}

Test(my_strncmp3 , compares_n_characters_of_two_strings3)
{
    cr_assert(my_strncmp("test", "test", 3) == 0);
}
