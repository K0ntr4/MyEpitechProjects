/*
** EPITECH PROJECT, 2021
** Rush 1
** File description:
**  int top_left_sign = signs[0];
**  int top_right_sign = signs[1];
**  int bot_left_sign = signs[2];
**  int bot_right_sign = signs[3];
**  int line_hor_sign = signs[4];
**  int line_ver_sign = signs[5];
*/

extern void generic_square(int x, int y, char signs[6]);

void rush(int x, int y)
{
    char signs[6] = {'A', 'C', 'C', 'A', 'B', 'B'};

    generic_square(x, y, signs);
}
