/*
** EPITECH PROJECT, 2021
** rush
** File description:
** displays a square
*/

extern void output(char c);
extern void output_error(char c);

void print(int x, int y, int i, int j)
{
    if ((j == 0 || j + 1 == x) && (i == 0 || i + 1 == y))
        output('o');
    else if ((i == 0 || i + 1 == y) && !(j == 0 || j + 1 == x))
        output('-');
    else
        trail(j, i, x);
}

void trail(int j, int i, int x)
{
    if (j == 0 || j + 1 == x)
        output('|');
    else
        output(' ');
}

int my_putstr(char const *str)
{
    int iter = 0;

    while (*(str + iter)) {
        output_error(*(str + iter));
        iter += 1;
    }
    output('\n');
    return (0);
}

void rush(int x, int y)
{
    int i = 0;
    int j = 0;
    char error[13] = "Invalid size";

    if (x <= 0 || y <= 0) {
        my_putstr(error);
        return (0);
    }
    while (i < y){
        while (j < x){
            print(x, y, i, j);
            j++;
        }
        j = 0;
        output('\n');
        i++;
    }
}
