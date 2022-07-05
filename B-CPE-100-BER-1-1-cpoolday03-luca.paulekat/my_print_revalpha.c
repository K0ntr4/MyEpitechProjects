/*
** EPITECH PROJECT, 2021
** my_print_revalpha
** File description:
** displays the lowercase alphabet in descending order
*/

int my_print_revalpha(void)
{
    char print;

    print = 122;
    while (print != 96) {
        write(1, &print, 1);
        print -= 1;
    }
    return (0);
}
