/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** desc
*/
#include "my.h"
#include "bootstrap.h"

void step2(char *cmd, char **argv, char **env)
{
    execve(cmd, argv, env);
}

char **append_string(char **str, char *item)
{
    char **new_str;
    int counter = 0;
    int i = 0;

    for (int i = 0; str[i]; i++)
        counter++;
    new_str = malloc(sizeof(char *) * (counter + 2));
    while (str[i]) {
        new_str[i] = malloc(sizeof(char) * (my_strlen(str[i]) + 1));
        my_strcpy(new_str[i], str[i]);
        free(str[i]);
        i++;
    }
    free(str);
    new_str[i] = malloc(sizeof(char) * (my_strlen(item) + 1));
    my_strcpy(new_str[i++], item);
    new_str[i] = NULL;
    return new_str;
}

char *append_char(char *str, char c)
{
    char *new_str;

    new_str = malloc(sizeof(char) * (my_strlen(str) + 3));
    my_strcpy(new_str, str);
    new_str[my_strlen(str)] = c;
    new_str[my_strlen(str) + 1] = '\0';
    free(str);
    return new_str;
}

char **init_arg_arr(char **argv, char **arg)
{
    int space_counter = 0;

    for (int j = 0; argv[1][j]; j++) {
        if (argv[1][j] == ' ')
            space_counter++;
    }
    arg = malloc(sizeof(char *) * (space_counter + 2));
    arg[0] = NULL;
    return arg;
}

char **split_args(char **argv)
{
    char *tmp = my_strdup("\0");
    int i = 0;
    char **arg;
    int strlen;

    arg = init_arg_arr(argv, arg);
    while (argv[1][i]) {
        if (argv[1][i] == ' ') {
            arg = append_string(arg, tmp);
            free(tmp);
            tmp = my_strdup("\0");
        }
        if (argv[1][i] != ' ')
            tmp = append_char(tmp, argv[1][i]);
        i++;
    }
    arg = append_string(arg, tmp);
    free(tmp);
    return arg;
}

int main(int argc , char **argv , char **env)
{
    char *args[]={"ls",NULL};
    char *envs[]={NULL};
    char cmd[] = {"/bin/ls"};
    char **arg;

    arg = split_args(argv);
    exec_print(argv, arg);
    for (int i = 0; arg[i]; i++) {
        my_putstr(arg[i]);
        free(arg[i]);
        my_putchar('\n');
    }
    free(arg);
    step2(cmd, args, envs);
}
