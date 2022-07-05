/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** displays either N if parameter negative or P, if positive or null
*/

int my_isneg(int n)
{
    char print;

    if (n < 0) {
        print = 'N';
    } else {
        print = 'P';
    }
    write(1, &print, 1);
    return (1);
}
