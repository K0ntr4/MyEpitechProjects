/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** capitalizes the first letter of each word
*/

extern int my_strlen(char const *str);

int check_upcase(int i, char *str)
{
    if (96 < str[i] && str[i] < 123 && !(str[i - 1] > 64 && str[i - 1] < 91))
        if (!(str[i - 1] > 96 && str[i - 1] < 123))
            return (1);
    return (0);
}

int check_lowcase(int i, char *str)
{
    if (91 > str[i] && str[i] > 64)
        if (!(str[i - 1] == 32 || str[i - 1] == 43 || str[i - 1] == 45))
            return (1);
    return (0);
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (check_upcase(i, str) == 1)
            str[i] -= 32;
        i++;
    }
    i = my_strlen(str);
    while (i > 0) {
        if (check_lowcase(i, str) == 1)
            str[i] += 32;
        i--;
    }
    return (str);
}
