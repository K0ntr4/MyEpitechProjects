/*
** EPITECH PROJECT, 2021
** test_my_strcapitalize.c
** File description:
** tests my_strncpy
*/
#include <criterion/criterion.h>

Test(my_strcapitalize , capitalizes_first_letter_of_all_words)
{
    char s1[60] = "hey, how are you? 42WORds forty-two; fifty+one";

    my_strcapitalize(s1);
    cr_assert_str_eq(s1, "Hey, How Are You? 42words Forty-Two; Fifty+One");
}
