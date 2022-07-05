/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** checks if string consists of only digits
*/

extern int my_strlen(char const *str);

int my_str_isnum(char const *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (str[i] < 58 && str[i] > 47)
            i++;
        else
            return (0);
    }
    return (1);
}
