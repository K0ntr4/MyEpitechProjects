/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** contains the prototypes of all the functions in libmy
*/

#ifndef my_ls_
    #define my_ls_

    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>

typedef struct my_ls_l {
    int flag_l;
    int flag_R;
    int flag_t;
    int flag_d;
    int flag_r;
    char *folder;
    char *rights;
    int n_link;
    char *pw;
    char *gr;
    int size;
    char *time;
    struct my_ls_l *next;
    struct my_ls_l *prev;
} my_ls_l;
typedef struct my_res_l {
    char *string;
    struct my_res_l *next;
    struct my_res_l *prev;
} my_res_l;
my_ls_l *to_end(my_ls_l **l);
my_ls_l *to_start(my_ls_l **l);
my_ls_l *new_elem(char *folder, int *flags);
void append_item(my_ls_l **l, char *folder, int *flags);
void *pop(my_ls_l **l);
int print_l(my_ls_l **l);
void *peek(my_ls_l *l);
void free_l(my_ls_l *l);
my_ls_l *remove_placeholder_l(my_ls_l **l);
int *get_flags(char *str, int *flags);
int prepare_my_ls(struct my_ls_l *folders, int *flags);
char *get_rights(struct stat stat);
int sort_list(my_ls_l **l , int(*c)(char const *, char const *));
int print_l_res(my_ls_l **l);
my_ls_l *rotate_list(my_ls_l *l);
int sort_list_by_time(my_ls_l **l , int(*c)(char *, char *, \
    my_ls_l *folders), my_ls_l *folders);
int cmptime(char *str1, char *str2, my_ls_l *folders);
int choose_my_ls(struct my_ls_l *res, struct my_ls_l *folders, int *flags);
int my_lsd(my_ls_l *folders, int *flags);
short includes(char *str, char c);
void my_lsl(struct my_ls_l *folders, struct my_ls_l *res, int *flags);
void check_dir(struct my_ls_l *folders, struct my_ls_l *res, int *flags);
int alpha_cmp(char const *s1 , char const *s2);

#endif
