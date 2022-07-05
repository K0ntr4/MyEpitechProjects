/*
** EPITECH PROJECT, 2021
** my_str_lower
** File description:
** checks if string consists of lower case characters
*/

extern int my_strlen(char const *str);

int my_str_islower(char const *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (str[i] < 123 && str[i] > 96)
            i++;
        else
            return (0);
    }
    return (1);
}
