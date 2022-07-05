/*
** EPITECH PROJECT, 2021
** my_show_word_array
** File description:
** prints out an array of strings
*/
#include <stdlib.h>

extern int my_putstr(char const *str);
extern int my_strlen(char const *str);

char *mallocing_p(char * const *argv)
{
    int i = 0;
    int l = 0;
    char *p;

    while (argv[i] != NULL) {
        l += my_strlen(argv[i]) + 1;
        i++;
    }
    p = malloc(sizeof(char) * (l + 1));
    return (p);
}

int my_show_word_array(char * const *tab)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *p = mallocing_p(tab);

    if (p == NULL)
        return (0);
    while (tab[i] != NULL) {
        while (j < my_strlen(tab[i])) {
            p[k++] = tab[i][j++];
            }
        p[k++] = '\n';
        j = 0;
        i++;
    }
    p[k] = '\0';
    my_putstr(p);
    free(p);
    return (1);
}
