/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** compares two strings
*/

extern int my_strlen(char const *str);

int my_strncmp(char const *s1 , char const *s2, int n)
{
    int i = 0;
    int dif = 0;
    int l1 = my_strlen(s1);
    int l2 = my_strlen(s2);

    while ((i < l2 || i < l1) && i <= n) {
        dif += s1[i] - s2[i];
        i++;
        if (dif < 0 || dif > 0)
            return (dif);
    }
    return (0);
}
