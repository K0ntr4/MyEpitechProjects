/*
** EPITECH PROJECT, 2021
** main
** File description:
** prints parameters given to the function in reverse order
*/

extern int my_putstr(char const *str);
extern void my_putchar(char c);

void my_print_params(int n, char **par)
{
    while (n > 0) {
        my_putstr(par[n - 1]);
        my_putchar('\n');
        n--;
    }
}

int main(int p, char **arg)
{
    my_print_params(p, arg);
    return (0);
}
