/*
** EPITECH PROJECT, 2021
** main
** File description:
** prints parameters given to the function in reverse order
*/

extern int my_putstr(char const *str);
extern void my_putchar(char c);
extern int my_strcmp(char const *s1 , char const *s2);

void output_param(int n, char **par)
{
    int i = 0;

    while (i < n) {
        my_putstr(par[i]);
        my_putchar('\n');
        i++;
    }
}

void my_print_params(int n, char **par)
{
    int i = 0;
    int counter = 0;
    char *p;

    while (n - 1 > i) {
        if (my_strcmp(par[i], par[i + 1]) > 0){
            p = par[i];
            par[i] = par[i + 1];
            par[i + 1] = p;
            counter++;
        }
        i++;
    }
    if (counter != 0){
        my_print_params(n, par);
    } else
        output_param(n, par);
}

int main(int p, char **arg)
{
    int i = 0;

    my_print_params(p, arg);
    return (0);
}
