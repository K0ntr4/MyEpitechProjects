/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** reverses a string
*/

extern int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int i = 0;
    int l = my_strlen(str);
    char tmp;

    while ((str[i] != '\0') && (i < l / 2)) {
        tmp = str[l - 1 - i];
        str[l - 1 - i] = str[i];
        str[i] = tmp;
        i++;
    }
    return (str);
}
