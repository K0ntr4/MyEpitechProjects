/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** concatenates two strings
*/

extern int my_strlen(char const *str);

char *my_strcat(char *dest , char const *src)
{
    int l = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[l + i] = src[i];
        i++;
    }
    dest[l + i] = '\0';
    return (dest);
}
