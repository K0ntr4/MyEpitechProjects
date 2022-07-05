/*
** EPITECH PROJECT, 2021
** concat_params
** File description:
** concats arguments into one string
*/
#include <stdlib.h>

extern int my_strlen(char const *str);

char *mallocing(int argc, char **argv)
{
    int i = 0;
    int l = 0;
    char *p;

    while (i < argc) {
        l += my_strlen(argv[i]) + 1;
        i++;
    }
    p = malloc(sizeof(char) * (l + 1));
    return (p);
}

char *concat_params(int argc , char **argv)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *p = mallocing(argc, argv);

    if (p == NULL)
        return (NULL);
    while (i < argc) {
        while (j < my_strlen(argv[i])) {
            p[k++] = argv[i][j++];
            }
        p[k++] = '\n';
        j = 0;
        i++;
    }
    p[k] = '\0';
    return (p);
}
