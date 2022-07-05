/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** concatenates n characters of two strings
*/

extern int my_strlen(char const *str);

char *my_strncat(char *dest , char const *src, int nb)
{
    int l = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0' && i < nb) {
        dest[l + i] = src[i];
        i++;
    }
    dest[l + i] = '\0';
    return (dest);
}
