/*
** EPITECH PROJECT, 2021
** my_print_comb
** File description:
** displays all the numbers composed by three different digits numbers
*/

void print_result(char f, char s, char t)
{
    char space = 32;
    char comma = 44;

    write(1, &f, 1);
    write(1, &s, 1);
    write(1, &t, 1);
    if (f != 55 || s != 56 || t != 57) {
        write(1, &comma, 1);
        write(1, &space, 1);
    }
}

int my_print_comb(void)
{
    char first = 48;
    char second = 48;
    char third = 48;

    while (first >= 48 && first <= 57) {
    if (third <= second || second <= first);
    else
        print_result(first, second, third);
    if (third == 57) {
        second += 1;
        third = 48;
    }
    if (second == 57 + 1) {
        first += 1;
        second = 48;
    }
    third += 1;
    }
    return (0);
}
