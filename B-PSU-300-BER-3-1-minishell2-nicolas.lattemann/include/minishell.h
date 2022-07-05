/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"

#ifndef B_PSU_300_BER_3_1_MINISHELL2_NICOLAS_LATTEMANN_MINISHELL_H
    #define B_PSU_300_BER_3_1_MINISHELL2_NICOLAS_LATTEMANN_MINISHELL_H
    #define KOWALSKI my_putstr("Kowalski, analysis.\n");
    #define EXIT_CMD "exit\0"
    #define PRINTENV "printenv\0"
    #define USER_INPUT_BUFF_SIZE 400
    #define UNSIGNED_LONG_MAX 4294967295
    #define APPEND (O_RDONLY | O_WRONLY | O_APPEND)
    #define CREATE (O_CREAT | O_RDONLY | O_WRONLY | O_TRUNC)
    #define OUTPUT_BUF 1000

    #include <sys/wait.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <errno.h>
    #include <string.h>
    #include <bits/types/FILE.h>

typedef struct env_var {
    char *name;
    char *value;
} env_var_t;

typedef struct command {
    char *command;
    char *dest;
    char *in;
} command_t;

list_t *my_setenv(char *name, char *value, list_t *env);

list_t *my_unsetenv(char *name, list_t *env);

list_t *real_my_env(list_t *env);

list_t *find_env_var(char *name, list_t *env);

char *get_env_var(char *name, list_t *env);

list_t *my_env(list_t *env);

env_var_t * prepare_set(char *str);

int is_env_var(char *str);

void printenv(list_t *env);

int minishell(list_t **env);

int my_cd(list_t **env, char *command);

char is_cd(char *command);

int verify_directory(char *full_path, char *path);

int execute_command(char *input, char **envp);

char *get_path(char **envp, char *input);

char **split_args(char *input, char split);

list_t *parse_command(char *cmd);

char **env_to_char_array(list_t *env);

int execute_input(char **arg, char **envp);

void do_child_process(char **arg, char **envp, char *cmd);

char **append_string(char **str, char *item);

int execute_command_chain(list_t *cmd_chain, list_t **env);

char *norm_user_input(char *input);

int un_setenv(char *cmd, list_t **env);

//src/execute/prepare_command_chain_helper.c
char *partial_copy(const char *string, int start, int end);

int to_skip(char c);

int get_start(const char *command, int start);

int get_end(const char *command, int end);

int is_ambiguous_redirect(char c, char last_sign);

int execute_rebuilds(command_t *command, list_t **env);

char *cd_get_path(list_t **env, char *command);

int update_string(char c, int string);

#endif //B_PSU_300_BER_3_1_MINISHELL2_NICOLAS_LATTEMANN_MINISHELL_H
