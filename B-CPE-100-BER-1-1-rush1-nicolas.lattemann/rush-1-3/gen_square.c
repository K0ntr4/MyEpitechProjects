/*
** EPITECH PROJECT, 2021
** Rush 1
** File description:
** Generic Square
*/

extern void my_putchar(char c);
extern void my_putstr(char *c);

void trail(char c, int length)
{
    int i = 0;

    while (i < length) {
        my_putchar(c);
        i += 1;
    }
}

void draw_first_char(int x, int y, char signs[6], int i)
{
    if (i == 0 && x > 1 && y > 1)
        my_putchar(signs[0]);
    else if (i == y - 1 && x > 1 && y > 1)
        my_putchar(signs[2]);
    else
        my_putchar(signs[4]);
}

void draw_last_char(int x, int y, char signs[6], int i)
{
    if (i == 0 && x > 1 && y > 1)
        my_putchar(signs[1]);
    else if (i == y - 1 && x > 1 && y > 1)
        my_putchar(signs[3]);
    else
        my_putchar(signs[4]);
}

void draw_trail(int x, int y, char signs[6], int i)
{
    if (i == 0)
        trail(signs[5], x - 2 > 0 ? x - 2 : 0);
    else if (i == y - 1)
        trail(signs[5], x - 2 > 0 ? x - 2 : 0);
    else
        trail(' ', x - 2 > 0 ? x - 2 : 0);
}

void generic_square(int x, int y, char signs[6])
{
    if (x < 1 || y < 1) {
        my_putstr("Invalid size\n");
        return;
    }
    for (int i = 0; i < y; i++) {
        draw_first_char(x, y, signs, i);
        draw_trail(x, y, signs, i);
        if (x > 1)
            draw_last_char(x, y, signs, i);
        my_putchar('\n');
    }
}
