/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** copies n characters of a string into another
*/

extern int my_strlen(char const *str);

char *my_strncpy(char *dest , char const *src, int n)
{
    int i = 0;
    int l = my_strlen(src);

    while (src[i] != '\0' && i < n) {
        if (n > l && i == n - 1)
            dest[i] = '\0';
        else
            dest[i] = src[i];
        i++;
    }
    if (src[i] == '\0')
        dest[i] = '\0';
    return (dest);
}
