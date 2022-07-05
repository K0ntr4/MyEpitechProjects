/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <lemin.h>
#include <stdio.h>

char **read_input(void)
{
    char *str = malloc(sizeof(char) * 1);
    char *new_str = NULL;
    char **new_string;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    str[0] = '\0';
    while ((read = getline(&line, &len, stdin)) != -1) {
        new_str = my_strcat(str, line);
        free(str);
        str = new_str;
    }
    free(line);
    new_str = my_strcat(str, "\0");
    free(str);
    str = new_str;
    new_string = split_string(str, '\n');
    free(str);
    return new_string;
}
