/*
** EPITECH PROJECT, 2021
** my_strlowcase
** File description:
** returns a string in lowercase
*/

extern int my_strlen(char const *str);

char *my_strlowcase(char *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
        i++;
    }
    return (str);
}
