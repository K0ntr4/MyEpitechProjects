/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** checks if string consists of upper case characters
*/

extern int my_strlen(char const *str);

int my_str_isupper(char const *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (str[i] < 91 && str[i] > 64)
            i++;
        else
            return (0);
    }
    return (1);
}
