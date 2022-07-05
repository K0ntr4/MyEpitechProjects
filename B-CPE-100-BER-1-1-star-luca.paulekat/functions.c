/*
** EPITECH PROJECT, 2021
** star
** File description:
** displays a star, based on its given size
*/

void side_top(int y, int size, int x)
{
    if (y == (x - size) || y == size * 6 - (x - size) - 1)
        output('*');
    else
        output(' ');
}

void side_bottom(int y, int size, int x)
{
    if (y == size - (x - size * 2) || y == size * 6 - size + (x - size * 2) - 1)
        output('*');
    else
        output(' ');
}

void top(int y, int size, int x)
{
    if (y == size * 3 + x || y == size * 3 - x)
        output('*');
    else
        output(' ');
}

void bottom(int y, int size, int x)
{
    if (y == size * 2 + x - size * 3 || y == size * 6 - (x - size))
        output('*');
    else
        output(' ');
}

void wing(int y, int size, int x)
{
    if (y <= size * 2 + 1 || y > size * 2 + 1 + (size - 1) * 2 - 1)
        output('*');
    else
        output(' ');
}
