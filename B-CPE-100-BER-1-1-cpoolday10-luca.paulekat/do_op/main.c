/*
** EPITECH PROJECT, 2021
** do_op
** File description:
** computes an operation
*/
#include <stddef.h>
#include "../include/my.h"

int my_puterror(char const *str);
int my_getnbr(char const *str);
int add(int nb1, int nb2);
int subtract(int nb1, int nb2);
int multiply(int nb1, int nb2);
int divide(int nb1, int nb2);
int modulo(int nb1, int nb2);

int perform_op(int first_nb, int second_nb, char **argv, int (*ops[])(int, int))
{
    int res;

    switch (argv[2][0]){
        case '+': res = ops[0](first_nb, second_nb); break;
        case '-': res = ops[1](first_nb, second_nb); break;
        case '*': res = ops[2](first_nb, second_nb); break;
        case '/': res = ops[3](first_nb, second_nb); break;
        case '%': res = ops[4](first_nb, second_nb); break;
    }
    return (res);
}

int division_by_zero(char **argv)
{
    if (my_getnbr(argv[3]) == 0 && argv[2][0] == '%') {
        my_puterror("Stop: modulo by zero\n");
        return (84);
    }
    if (my_getnbr(argv[3]) == 0 && argv[2][0] == '/') {
        my_puterror("Stop: division by zero\n");
        return (84);
    }
    return (0);
}

int check_ops(char **argv)
{
    if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*')
        if (argv[2][0] != '/' && argv[2][0] != '%')
            return (84);
    return (0);
}

int main(int argc, char **argv)
{
    int (*ops[5])(int, int) = {&add, &subtract, &multiply, &divide, &modulo};
    int res;

    if (argc != 4 || division_by_zero(argv) == 84)
        return (84);
    if (check_ops(argv) == 84) {
        my_putchar(48);
        return (84);
    }
    if (argc == 4){
        res = perform_op(my_getnbr(argv[1]), my_getnbr(argv[3]), argv, ops);
        my_put_nbr(res);
        return (0);
    }
}
