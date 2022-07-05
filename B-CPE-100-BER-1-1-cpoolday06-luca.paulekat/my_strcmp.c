/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** compares two strings
*/

extern int my_strlen(char const *str);

int my_strcmp(char const *s1 , char const *s2)
{
    int i = 0;
    int dif = 0;
    int l1 = my_strlen(s1);
    int l2 = my_strlen(s2);

    while ((i < l2 || i < l1)) {
        dif += s1[i] - s2[i];
        i++;
        if (dif < 0)
            return (-1);
        if (dif > 0)
            return (1);
    }
    return (0);
}
