/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** copies a string into another
*/

char *my_strcpy(char *dest , char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    if (src[i] == '\0')
        dest[i] = src[i];
    return (dest);
}
