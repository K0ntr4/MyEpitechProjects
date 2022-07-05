/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** desc
*/
#include "my.h"
#include "myls.h"

void my_ls(struct my_ls_l *res, struct my_ls_l *folders, int *flags)
{
    char *new_string;

    while (res && res->next) {
        new_string = malloc(sizeof(char) * my_strlen(res->folder) + 2);
        my_strcpy(new_string, res->folder);
        free(res->folder);
        res->folder = my_strcat(new_string, " \0");
        check_dir(folders, res, flags);
        res = res->next;
    }
    new_string = malloc(sizeof(char) * my_strlen(res->folder) + 2);
    my_strcpy(new_string, res->folder);
    free(res->folder);
    res->folder = my_strcat(new_string, " \0");
    check_dir(folders, res, flags);
}

int choose_my_ls(struct my_ls_l *res, struct my_ls_l *folders, int *flags)
{
    if (folders->flag_l == 1)
        my_lsl(folders, res, flags);
    else
        my_ls(res, folders, flags);
    sort_list(&res, &alpha_cmp);
    to_start(&res);
    if (res->flag_t == 1)
        sort_list_by_time(&res, &cmptime, folders);
    if (res->flag_r == 1)
        rotate_list(res);
}

void print_r_flag (struct my_ls_l *folders)
{
    my_putstr(folders->folder);
    my_putstr(":\n");
}

void print_res(struct my_ls_l *res)
{
    print_l_res(&res);
    free_l(res);
}

int prepare_my_ls(struct my_ls_l *folders, int *flags)
{
    DIR *directory;
    struct dirent *dirp;
    struct my_ls_l *res = NULL;

    for (int i = 0; folders; i++) {
        directory = opendir(folders->folder);
        if (directory == NULL)
            return 84;
        if (folders->flag_R == 1)
            print_r_flag(folders);
        while ((dirp = readdir(directory)) != NULL) {
            if (dirp->d_name[0] != '.')
                append_item(&res, dirp->d_name, flags);
        }
        choose_my_ls(res, folders, flags);
        closedir(directory);
        print_res(res);
        folders = folders->next;
        res = NULL;
    }
}