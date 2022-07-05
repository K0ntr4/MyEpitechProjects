/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** returns a string in uppercase
*/

extern int my_strlen(char const *str);

char *my_strupcase(char *str)
{
    int i = 0;

    while (i < my_strlen(str)) {
        if (str[i] > 96 && str[i] < 123)
            str[i] -= 32;
        i++;
    }
    return (str);
}
