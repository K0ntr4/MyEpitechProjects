/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include <criterion/criterion.h>

#include "my.h"
#include "header.h"
#include "parser.h"

Test(bistromatic, decimal_1)
{
    char *expression = my_strdup("29+83");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("0123456789");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("112", bistromatic(argv, expression));
}

Test(bistromatic, decimal_2)
{
    char *expression = my_strdup("-(12-(4*32))");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("0123456789");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("116", bistromatic(argv, expression));
}

Test(bistromatic, decimal_3)
{
    char *expression = my_strdup("-(e@-(;*!@))");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("0A@!;ie& ]");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("ee", bistromatic(argv, expression));
}

Test(bistromatic, decimal_4)
{
    char *expression = my_strdup("-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("0123456789");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("-744629760", bistromatic(argv, expression));
}

Test(bistromatic, decimal_5)
{
    char *expression = my_strdup("----++-6*12");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("0123456789");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("-72", bistromatic(argv, expression));
}

Test(bistromatic, ops_1)
{
    char *expression = my_strdup("3v6");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("0123456789");
    argv[2] = my_strdup("{}vwxyz");
    cr_expect_str_eq("9", bistromatic(argv, expression));
}

Test(bistromatic, hexa_1)
{
    char *expression = my_strdup("F+FF");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("0123456789ABCDEF");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("10E", bistromatic(argv, expression));
}

Test(bistromatic, hexa_2)
{
    char *expression = my_strdup("2C02F4A4396C3CDCB7690B99D37F528C3C92A/A7D6631EABC4594F3C87CA55F75763AC");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("0123456789ABCDEF");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("43215", bistromatic(argv, expression));
}

Test(bistromatic, hexa_3)
{
    char *expression = my_strdup("43215*-21C79F183EB");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("0123456789ABCDEF");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("-8DBA3ED3C3FB847", bistromatic(argv, expression));
}

Test(bistromatic, hexa_4)
{
    char *expression = my_strdup("-8DBA3ED3C3FB847%253A46E8B");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("0123456789ABCDEF");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("-22F3B895E", bistromatic(argv, expression));
}

Test(bistromatic, binary_1)
{
    char *expression = my_strdup("100000+1010");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("01");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("101010", bistromatic(argv, expression));
}

Test(bistromatic, binary_2)
{
    char *expression = my_strdup("(100000+1010)*100/-1");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("01");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("-10101000", bistromatic(argv, expression));
}

Test(bistromatic, binary_custom_1)
{
    char *expression = my_strdup("10N10100000");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("01");
    argv[2] = my_strdup("()MN*/%");
    cr_expect_str_eq("N10011110", bistromatic(argv, expression));
}

Test(bistromatic, hexadecimal_1)
{
    char *expression = my_strdup("((67A87AAB1E632EDC79B2E*6CB183E3391C7CB3/A7D6631EABC4594F3C87CA55F75763AC)*-21C79F183EB)%253A46E8B");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("0123456789ABCDEF");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("-22F3B895E", bistromatic(argv, expression));
}

Test(bistromatic, hexadecimal_2)
{
    char *expression = my_strdup("(67A87AAB1E632EDC79B2E*6CB183E3391C7CB3/A7D6631EABC4594F3C87CA55F75763AC)*-21C79F183EB");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("0123456789ABCDEF");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("-8DBA3ED3C3FB847", bistromatic(argv, expression));
}

Test(bistromatic, hexadecimal_custom_1)
{
    char *expression = my_strdup("((67A87AAB1E632EDC79B2E*6CB183E3391C7CB3/A7D6631EABC4594F3C87CA55F75763AC)*-21C79F183EB)%253A46E8B");
    char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("0123456789ABCDEF");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("-22F3B895E", bistromatic(argv, expression));
}

Test(bistromatic, binary_3)
{
    char *expression = my_strdup("1*(-1/1)");

        char **argv = malloc(sizeof(char *) * 3);

    argv[1] = my_strdup("01");
    argv[2] = my_strdup("()+-*/%");
    cr_expect_str_eq("-1", bistromatic(argv, expression));
}
