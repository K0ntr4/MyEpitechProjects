/*
** EPITECH PROJECT, 2021
** MY_STRCMP
** File description:
** desc
*/

extern int my_strlen(char const *str);

char get_char(char *str, int i)
{
    if (str[i] >= 65 && str[i] <= 90)
        return str[i] + 32;
    else if (str[i] <= 96 && !(str[i] >= 65 && str[i] <= 90 || str[i] == 0))
        return (126);
    else
        return str[i];
}

int alpha_cmp(char *s1 , char *s2)
{
    int i = 0;
    int dif = 0;
    int l1 = my_strlen(s1);
    int l2 = my_strlen(s2);

    while (i < l2 || i < l1) {
        dif += get_char(s1, i) - get_char(s2, i);
        i++;
        if (dif < 0)
            return (-1);
        if (dif > 0)
            return (1);
    }
        return 1;
    return (0);
}
