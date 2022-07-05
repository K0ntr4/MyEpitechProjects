/*
** EPITECH PROJECT, 2021
** main
** File description:
** prints parameters given to the function
*/

extern int my_putstr(char const *str);
extern void my_putchar(char c);

void my_print_params(int n, char **par)
{
    int i = 0;

    while (i < n) {
        my_putstr(par[i]);
        my_putchar('\n');
        i++;
    }
}

int main(int p, char **arg)
{
    my_print_params(p, arg);
    return (0);
}
