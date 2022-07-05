/*
** EPITECH PROJECT, 2021
** my_print_digits
** File description:
** displays all the digits, on a single line, in ascending order
*/

int my_print_digits(void)
{
    char print;

    print = 48;
    while (print != 58) {
        write(1, &print, 1);
        print += 1;
    }
    return (1);
}
