/*
** EPITECH PROJECT, 2021
** my_str_isprintable
** File description:
** checks if string is printable
*/

extern int my_strlen(char const *str);

int my_str_isprintable(char const *str)
{
    int i = 0;
    int l = my_strlen(str);

    if (l == 0)
        return (1);
    while (i < l) {
        if ((str[i] != 0 && str[i] < 32) || str[i] == 127)
            return (0);
        else
            i++;
    }
    return (1);
}
