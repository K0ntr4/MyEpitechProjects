/*
** EPITECH PROJECT, 2021
** my_strstr
** File description:
** finds a string inside another
*/
#include <stddef.h>

extern int my_strlen(char const *str);

char *my_strstr(char *str , char const *to_find)
{
    int i = 0;
    int n = 0;
    char *p;
    int l = my_strlen(str);

    if (l == 0)
        return (NULL);
    while (str[i] != '\0') {
        if (str[i] == to_find[n] && to_find[n] != '\0'){
            n++;
        } else if (to_find[n] == 0) {
                p = str + (i - n);
                return (p);
        }
        i++;
    }
    p = str + (i - n);
    return (p);
}
