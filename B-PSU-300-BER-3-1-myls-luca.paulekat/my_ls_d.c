/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** desc
*/
#include "my.h"
#include "myls.h"

int my_lsd(my_ls_l *folders, int *flags)
{
    DIR *directory;
    struct my_ls_l *res = NULL;

    for (int i = 0; folders && folders->next;) {
        directory = opendir(folders->folder);
        if (directory == NULL)
            return 84;
        append_item(&res, folders->folder, flags);
        folders = folders->next;
    }
    directory = opendir(folders->folder);
    if (directory == NULL)
        return 84;
    append_item(&res, folders->folder, flags);
    to_start(&res);
    choose_my_ls(res, folders, flags);
    closedir(directory);
    print_l_res(&res);
    free_l(res);
    res = NULL;
}