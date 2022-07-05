/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** desc
*/
#include "my.h"
#include "bootstrap.h"

int exec_print(char **argv, char **arg)
{
    int nb_arg = 0;
    char *program_name = arg[0];
    int p_pid = getpid();
    int p_id;
    int pid;
    int status;

    for (int j = 0; argv[1][j]; j++) {
        if (argv[1][j] == ' ')
            nb_arg++;
    }
    my_putstr("Program name: \0");
    my_putstr(program_name);
    my_putchar('\n');
    my_putstr("Nb args: \0");
    my_put_nbr(nb_arg);
    my_putchar('\n');
    my_putstr("PID: \0");
    my_put_nbr(p_pid);
    my_putchar('\n');
    pid = fork();
    if (pid == 0) {
        my_putstr("Child PID: \0");
        p_id = getpid();
        my_put_nbr(p_id);
        my_putchar('\n');
        my_putstr("... . .\n... . .\n... . . \0");
        execve(arg[0], arg, NULL);
    } else if (pid < 0) {
        my_putstr("error");
    } else {
        int status;
        if (wait(&pid) >= 0) {
            my_putstr("\n... . .\n... . .\nProgram terminated.\nStatus: \0");
            my_put_nbr(WEXITSTATUS(status));
            my_putchar('\n');
        }
    }
    return 0;
}