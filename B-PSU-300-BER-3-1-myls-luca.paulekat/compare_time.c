/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** desc
*/
#include "my.h"
#include "myls.h"

int get_comparison(long tmp, struct stat info)
{
    if (tmp < info.st_mtime)
        return -1;
    else if (tmp == info.st_mtime)
        return 0;
    else
        return 1;
}

int cmptime(char *str1, char *str2, my_ls_l *folders)
{
    char *filename;
    long tmp;
    struct stat info;

    filename = malloc(sizeof(char) * \
        (my_strlen(folders->folder) + my_strlen(str1)) + 2);
    my_strcpy(filename, folders->folder);
    filename = my_strcat(my_strcat(filename, "/\0"), str1);
    stat(filename, &info);
    tmp = info.st_mtime;
    filename = malloc(sizeof(char) * \
        (my_strlen(folders->folder) + my_strlen(str2)) + 2);
    my_strcpy(filename, folders->folder);
    filename = my_strcat(my_strcat(filename, "/\0"), str2);
    stat(filename, &info);
    return (get_comparison(tmp, info));
}

int sort_list_by_time(my_ls_l **l , int(*c)(char *, char *, \
    my_ls_l *folders), my_ls_l *folders)
{
    my_ls_l *tmp_next;
    my_ls_l *tmp_prev;
    int i = 0;
    int counter = 0;

    to_start(l);
    while (*l && (*l)->next) {
        if (c((*l)->folder, (*l)->next->folder, folders) > 0) {
            tmp_next = (*l)->next->next;
            tmp_prev = (*l)->prev;
            (*l)->next->next = *l;
            (*l)->prev = (*l)->next;
            if (tmp_prev)
                tmp_prev->next = (*l)->prev;
            (*l)->prev->prev = tmp_prev;
            (*l)->next = tmp_next;
            if ((*l)->next)
                (*l)->next->prev = *l;
            counter++;
        } else {
            *l = (*l)->next;
        }
    }
    to_start(l);
    if (counter != 0)
        sort_list_by_time(l, c, folders);
    else
        return (0);
    return (84);
}