/*
** EPITECH PROJECT, 2021
** parsing
** File description:
** desc
*/

#include <criterion/criterion.h>

#include "my.h"
#include "lemin.h"

Test(parsing, simple1)
{
    char *str[13] = {my_strdup("3"), my_strdup("2 5 0"), my_strdup("##start"), my_strdup("0 1 2"), \
        my_strdup("##end"), my_strdup("10 9 2"), my_strdup("3 5 4"), my_strdup("0-2"), \
        my_strdup("0-3"), my_strdup("2-10"), my_strdup("3-10"), my_strdup("2-3"), NULL};
    int n = 0;

    room_t *res = parse_input(str, &n);
    cr_expect_str_eq("0", res->name);
}

Test(parsing, simple2)
{
    char *str[13] = {my_strdup("3"), my_strdup("##start"), my_strdup("2 5 0"), my_strdup("0 1 2"), \
        my_strdup("##end"), my_strdup("10 9 2"), my_strdup("3 5 4"), my_strdup("0-2"), \
        my_strdup("0-3"), my_strdup("2-10"), my_strdup("3-10"), my_strdup("2-3"), NULL};
    int n = 0;

    room_t *res = parse_input(str, &n);
    cr_expect_str_eq("2", res->name);
}

Test(parsing, comment1)
{
    char *str[14] = {my_strdup("3"), my_strdup("2 5 0"), my_strdup("##start"), my_strdup("0 1 2"), \
        my_strdup("##end"), my_strdup("10 9 2"), my_strdup("#command"), my_strdup("3 5 4"), my_strdup("0-2"), \
        my_strdup("0-3"), my_strdup("2-10"), my_strdup("3-10"), my_strdup("2-3"), NULL};
    int n = 0;

    room_t *res = parse_input(str, &n);
    cr_expect_str_eq("0", res->name);
}

Test(parsing, comment2)
{
    char *str[16] = {my_strdup("3"), my_strdup("2 5 0"), my_strdup("##start"), my_strdup("#command"), my_strdup("#second command"), my_strdup("0 1 2"), \
        my_strdup("##end"), my_strdup("10 9 2"), my_strdup("#command"), my_strdup("3 5 4"), my_strdup("0-2"), \
        my_strdup("0-3"), my_strdup("2-10"), my_strdup("3-10"), my_strdup("2-3"), NULL};
    int n = 0;

    room_t *res = parse_input(str, &n);
    cr_expect_str_eq("0", res->name);
}

Test(parsing, comment3)
{
    char *str[17] = {my_strdup("#test"), my_strdup("3"), my_strdup("2 5 0"), my_strdup("##start"), my_strdup("#command"), my_strdup("#second command"), my_strdup("0 1 2"), \
        my_strdup("##end"), my_strdup("10 9 2"), my_strdup("#command"), my_strdup("3 5 4"), my_strdup("0-2"), \
        my_strdup("0-3"), my_strdup("2-10"), my_strdup("3-10"), my_strdup("2-3"), NULL};
    int n = 0;

    room_t *res = parse_input(str, &n);
    cr_expect_str_eq("0", res->name);
}

Test(parsing, n_rooms1)
{
    char *str[14] = {my_strdup("3"), my_strdup("2 5 0"), my_strdup("##start"), my_strdup("0 1 2"), \
        my_strdup("##end"), my_strdup("10 9 2"), my_strdup("#command"), my_strdup("3 5 4"), my_strdup("0-2"), \
        my_strdup("0-3"), my_strdup("2-10"), my_strdup("3-10"), my_strdup("2-3"), NULL};
    int n = 0;

    parse_input(str, &n);
    cr_expect_eq(4, n);
}

Test(parsing, n_rooms2)
{
    char *str[15] = {my_strdup("3"), my_strdup("2 5 0"), my_strdup("##start"), my_strdup("0 1 2"), \
        my_strdup("##end"), my_strdup("10 9 2"), my_strdup("1 5 2"), my_strdup("#command"), my_strdup("3 5 4"), my_strdup("0-2"), \
        my_strdup("0-3"), my_strdup("2-10"), my_strdup("3-10"), my_strdup("2-3"), NULL};
    int n = 0;

    parse_input(str, &n);
    cr_expect_eq(5, n);
}