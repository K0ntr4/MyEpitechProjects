/*
** EPITECH PROJECT, 2021
** my_putstr
** File description:
** displays , one-by-one, the characters of a string
*/

int my_putstr(char const *str)
{
    int length = 0;
    char arr = *str;

    while (str[length] != '\0'){
        write(1, &str[length], 1);
        length += 1;
    }
    return (0);
}
