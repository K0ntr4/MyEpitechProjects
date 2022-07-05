/*
** EPITECH PROJECT, 2021
** my_print_alpha
** File description:
** displays the lowercase alphabet in ascending order
*/

int my_print_alpha(void)
{
    char print;

    print = 97;
    while (print != 123) {
        write(1, &print, 1);
        print += 1;
    }
    return (1);
}
