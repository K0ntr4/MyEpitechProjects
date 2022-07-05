/*
** EPITECH PROJECT, 2021
ma** EvalExpr
** File description:
** test
*/

#include <criterion/criterion.h>

#include "my.h"
#include "header.h"
#include "parser.h"

Test(evaluate, 1)
{
    char *expression = my_strdup("29+83");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("112", root->item);
}

Test(evaluate, 2)
{
    char *expression = my_strdup("-(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*(-(12-98*42)*(16+63-50/3))");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("-744629760", root->item);
}

Test(evaluate, 3)
{
    char *expression = my_strdup("(2+12)*(5*(4*32))");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("8960", root->item);
}

Test(evaluate, 4)
{
    char *expression = my_strdup("2+12-(5*(4*32))");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("-626", root->item);
}

Test(evaluate, 5)
{
    char *expression = my_strdup("2*(2+8)*5+(4+3)");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("107", root->item);
}

Test(evaluate, 6)
{
    char *expression = my_strdup("(12*(13+15/5*(6/(12+14%(30%5+(10*25)-46)+16)-20)/43)*20)*((12-98*42)*(16+63-50/3))");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("-744629760", root->item);
}

Test(evaluate, 7)
{
    char *expression = my_strdup("2*(2+8)*5+(4+3)-9");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("98", root->item);
}

Test(evaluate, 8)
{
    char *expression = my_strdup("2*(2+-8)/5+(4+3)--9");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("14", root->item);
}

Test(evaluate, 9)
{
    char *expression = my_strdup("3+-(3*3)");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("-6", root->item);
}

Test(evaluate, 10)
{
    char *expression = my_strdup("(2+-12)*(5*(4*32))/2");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("-3200", root->item);
}

Test(evaluate, 11)
{
    char *expression = my_strdup("-12*(13+15+5)/2");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("-198", root->item);
}

Test(evaluate, 12)
{
    char *expression = my_strdup("(-(12-98*42)*(16+63-50/3))");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("258552", root->item);
}

Test(evaluate, 13)
{
    char *expression = my_strdup("-(2*(3+3)+2)");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("-14", root->item);
}

Test(evaluate, 14)
{
    char *expression = my_strdup("3+42*(1-2/(3+4)-1%21)+2");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("5", root->item);
}

Test(evaluate, 15)
{
    char *expression = my_strdup("----++-6*12");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("-72", root->item);
}

Test(evaluate, 16)
{
    char *expression = my_strdup("----++-(6*12)");
    ast_t *root = parse_expression(expression, 10);

    eval_tree(root);
    cr_expect_str_eq("-72", root->item);
}
