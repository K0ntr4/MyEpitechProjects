/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** desc
*/
#include "my.h"
#include "minishell.h"
#include <stdio.h>

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

char **init_arg_arr(char *input, char **arg, char split)
{
    int space_counter = 0;

    for (int j = 0; input[j]; j++) {
        if (input[j] == split)
            space_counter++;
    }
    arg = malloc(sizeof(char *) * (space_counter + 2));
    arg[0] = NULL;
    return arg;
}

char **split_args(char *input, char split)
{
    char *tmp = my_strdup("\0");
    int i = 0;
    char **arg = init_arg_arr(input, NULL, split);
    int string = 0;

    while (input[i]) {
        string = update_string(input[i], string);
        if (input[i] == split && string == 0) {
            arg = append_string(arg, tmp);
            free(tmp);
            tmp = my_strdup("\0");
        }
        if (input[i] != split || string == 1)
            tmp = append_char(tmp, input[i]);
        i++;
    }
    arg = append_string(arg, tmp);
    free(tmp);
    return arg;
}

int execute_command(char *input, char **envp)
{
    char **arg = split_args(input, ' ');
    int exit_code = 0;
    int pid;

    if ((pid = fork()) == -1) {
        my_puterror(strerror(errno));
        my_putchar('\n');
        return 84;
    } else if (pid == 0) {
        do_child_process(arg, envp, get_path(envp, arg[0]));
    } else
        waitpid(pid, &exit_code, 0);
    return 0;
}
