/*
** EPITECH PROJECT, 2021
** get_color
** File description:
** returns an int of RGB Value
*/

int get_color(unsigned char red, unsigned char green, unsigned char blue)
{
    int c;

    c = red;
    c = c << 8;
    c += green;
    c = c << 8;
    c += blue;
    return (c);
}
