/*
** EPITECH PROJECT, 2021
** concat_params
** File description:
** concats arguments into one string
*/
#include <stdlib.h>

extern int my_putstr(char const *str);
extern int my_strlen(char const *str);
extern int my_show_word_array(char * const *tab);
extern int get_array_len(char const *str);

int check_a(char const *str, int i)
{
    int test;

    if (str[i] >= 97 && str[i] <= 122 || str[i] >= 65 && str[i] <= 90) {
        test = 1;
    } else if (str[i] >= 48 && str[i] <= 57) {
        test = 1;
    } else {
        test = 0;
    }
    return (test);
}

int check_a2(char const *str, int i)
{
    while (str[i] && check_a(str, i) == 0) {
        i++;
        }
    return (i);
}

int n_char(char const *str, int i)
{
    int n = 0;

    while (str[i] && check_a(str, i) == 1) {
        i++;
        n++;
    }
    return (n);
}

int loop(int j, char const *str, char **p, int *i)
{
    int k = 0;

    if (check_a(str, *i) == 1) {
        p[j] = malloc(sizeof(char) * (n_char(str, *i) + 1));
        while (*i < my_strlen(str) && str[*i] != '\0' && check_a(str, *i) == 1){
            p[j][k++] = str[*i];
            *i += 1;
        }
        p[j][k] = '\0';
    } else if (*i < my_strlen(str)){
        *i = check_a2(str, *i);
        j--;
    }
    return(j);
}

char **my_str_to_word_array(char const *str)
{
    int x = 0;
    int *i = &x;
    int k = 0;
    int j = 0;
    char **p = malloc(sizeof(char *) * (get_array_len(str) + 1));

    for (j; j < get_array_len(str); j++) {
        j = loop(j, str, p, i);
    }
    p[j] = NULL;
    return (p);
}
