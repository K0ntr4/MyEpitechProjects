/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#include <stddef.h>
#include <stdlib.h>

#include "my.h"
#include "header.h"
#include "parser.h"

static void process_stack(list_t **ast_stack, list_t **operators, char *item)
{
    char *prev_item = NULL;

    while (*operators && (NULL != (prev_item = peek(*operators)))) {
        if (prev_item[0] == '(')
            break;
        if (compare_precedence(item, prev_item) >= 0)
            add_node(ast_stack, pop(operators));
        else
            break;
    }
    append_item(operators, item);
}

void par_stack(list_t **ast_stack, list_t **operators,  char **p_expr, int base)
{
    char *prev_item = NULL;

    while (*operators) {
        prev_item = pop(operators);
        if (prev_item[0] == '(') {
            free(prev_item);
            parse(ast_stack, operators, p_expr, base);
            return;
        } else {
            add_node(ast_stack, prev_item);
        }
    }
    my_putstr(SYNTAX_ERROR_MSG);
    exit(84);
}

void parse(list_t **ast_stack, list_t **operators, char **p_expr, int base)
{
    char *item = NULL;

    while (*p_expr[0] && *p_expr[0] != '#') {
        item = get_next_item(p_expr, base);
        switch (item[0]) {
        case '$': insert_neg_par(ast_stack, operators, item); break;
        case '(': append_item(operators, item); break;
        case ')':
            free(item);
            return par_stack(ast_stack, operators, p_expr, base);
        default:
            if (includes(OPER, item[0]) && item[1] == '\0')
                process_stack(ast_stack, operators, item);
            else
                append_item(ast_stack, new_ast_node(item, NULL, NULL));
        }
    }
    while (*operators)
        add_node(ast_stack, pop(operators));
}

ast_t *parse_expression(char *expression, int base)
{
    list_t *ast_stack = NULL;
    list_t *operators = NULL;
    char *preped_expr = prep_expression(expression);
    char *expr = &preped_expr[1];
    ast_t *root = NULL;

    parse(&ast_stack, &operators, &expr, base);
    root = ast_stack->item;
    free_list(operators);
    free(preped_expr);
    free(ast_stack);
    return root;
}
