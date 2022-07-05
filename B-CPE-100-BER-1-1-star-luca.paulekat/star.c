/*
** EPITECH PROJECT, 2021
** star
** File description:
** displays a star, based on its given size
*/

#include functions.c

extern void side_top(int y, int size, int x);
extern void side_bottom(int y, int size, int x);
extern void top(int y, int size, int x);
extern void bottom(int y, int size, int x);
extern void wing(int y, int size, int x);

void star(unsigned int size)
{
    int x = 0;
    int y = 0;

    while (x < size * 4 + 1) {
        print(x, size, y);
        output('\n');
        y = 0;
        x++;
    }
}

void print(int x, int size, int y)
{
    while ((y < ((size * 6) / 2) + 1 + x) && (x < size)){
        top(y, size, x);
        y++;
    }
    while ((y < size * 6) && (x == size || x == size * 3)){
        wing(y, size, x);
        y++;
    }
    while ((x > size && x < size * 2 + 1) && y < size * 6 - (x - size)){
        side_top(y, size, x);
        y++;
    }
    while ((x < size * 3 && x > size * 2) && y < size * 6 - size * 3 + x){
        side_bottom(y, size, x);
        y++;
    }
    while ((x > size * 3) && y < size * 6 - (x - size) + 1){
        bottom(y, size, x);
        y++;
    }
}

void output(char c)
{
    write(1, &c, 1);
}
