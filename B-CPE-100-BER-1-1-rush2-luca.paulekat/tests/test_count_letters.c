/*
** EPITECH PROJECT, 2021
** RUSH2
** File description:
** letters_in_str
*/

#include <criterion/criterion.h>
#include "my.h"
#include "header.h"

extern int main(int argc, char **argv);

Test(letters_in_str, 10)
{
    char *str = my_strdup("Hello world");

    cr_expect_eq(10, letters_in_str(str));
}

Test(letters_in_str, 14)
{
    char *str = my_strdup("Hello!! zero !! world");

    cr_expect_eq(14, letters_in_str(str));
}

Test(letters_in_str, 0)
{
    char *str = my_strdup("");

    cr_expect_eq(0, letters_in_str(str));
}
