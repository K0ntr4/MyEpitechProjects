/*
** EPITECH PROJECT, 2021
** Bistromatic
** File description:
** desc
*/

#ifndef PARSER_H_
    #define  PARSER_H_
    #define OPER "*/%+-()"
    #define DOT "*/%"
    #define DASH "+-"

typedef struct ast {
    struct ast *left;
    struct ast *right;
    char *item;
} ast_t;

typedef struct lin_list {
    struct lin_list *next;
    struct lin_list *prev;
    void *item;
} list_t;

list_t *to_end(list_t **list);

list_t *to_start(list_t **list);

list_t *new_elem(void *item);

void append_item(list_t **list, void *item);

void *pop(list_t **list);

int print_list(list_t **list);

int print_ast(ast_t *root, int level);

ast_t *parse_expression(char *expression, int base);

char *resize(char *str, int n);

short is_num(char c);

ast_t *new_ast_node(char *item, ast_t *left, ast_t *right);

int compare_precedence(char *op1, char *op2);

void *peek(list_t *list);

char *prep_expression(char *str);

void eval_tree(ast_t *node);

void free_list(list_t *list);

void  add_node(list_t **ast_stack, char *oper);

int is_par(char *expr);

int is_neg_par(char *expr);

char *get_next_item(char **p_expr, int base);

void insert_neg_par(list_t **ast_stack, list_t **operators, char *item);

void parse(list_t **ast_stack, list_t **operators, char **p_expr, int base);

int free_ast(ast_t *node);

#endif
