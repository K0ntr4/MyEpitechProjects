/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** desc
*/

#include "my.h"
#include "minishell.h"

char *my_remove(char *str, char c)
{
    int counter = 0;
    int j = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == c) {
            counter++;
            j = i + 1;
            while (str[j] != '\0') {
                str[j - 1] = str[j];
                j++;
            }
            str[j - 1] = '\0';
            j = 0;
            i--;
        }
    }
    return (str);
}

void do_error_print(int error)
{
    my_puterror(strerror(error));
    my_puterror("\n");
}

void do_child_process(char **arg, char **envp, char *cmd)
{
    int exit_val = 0;

    if ((my_strcmp(cmd, arg[0]) == 0 && (cmd[0] != '.' || cmd[1] != '/')))
        if (my_strcmp(arg[0], "setenv") != 0) {
            my_puterror(cmd);
            my_puterror(": Command not found.\n");
            exit(84);
        }
    for (int i = 1; arg[i]; i++)
        arg[i] = my_remove(arg[i], '"');
    if (my_strcmp(arg[0], PRINTENV) == 0 || my_strcmp(arg[0], "setenv") == 0) {
        my_show_word_array(envp);
        exit(0);
    }
    exit_val = execve(cmd, arg, envp);
    if (errno != 0) {
        do_error_print(errno);
        exit(errno);
    }
    exit(exit_val);
}

char *test_paths(char **paths, char *input)
{
    char *command;

    for (int i = 0; i < arr_length(paths); i++) {
        command = my_strcat(my_strcat(paths[i], "/"), input);
        if (access(command, F_OK) == 0)
            return command;
    }
    return input;
}

char *get_path(char **envp, char *input)
{
    char *res;
    char **paths;
    list_t *env_variables = NULL;

    for (int i = 0; envp[i]; i++) {
        append_item(&env_variables, prepare_set(envp[i]));
    }
    res = get_env_var("PATH", env_variables);
    if (!res)
        return input;
    paths = split_args(res, ':');
    return test_paths(paths, input);
}
