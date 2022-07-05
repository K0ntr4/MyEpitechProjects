/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** capitalizes the first letter of each word
*/

extern int my_strlen(char const *str);

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if ((str[i] < 91 && str[i] > 64) || (str[i] < 123 && str[i] > 96))
            i++;
        else
            return (0);
    }
    return (1);
}
