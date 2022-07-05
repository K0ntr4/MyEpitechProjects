/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** desc
*/
#include "my.h"
#include "myls.h"

int main(int ac, char **av)
{
    int flags[5] = {0, 0, 0, 0, 0};
    struct my_ls_l *folders = NULL;
    int counter = 0;

    for (int j = 1; j < ac; j++) {
        if (av[j][0] == '-') {
            get_flags(av[j], flags);
        } else {
            append_item(&folders, av[j], flags);
            counter++;
        }
    }
    if (flags[0] == 2)
        return (84);
    if (counter == 0)
        append_item(&folders, "./", flags);
    if (folders->flag_d == 1)
        return (my_lsd(folders, flags));
    prepare_my_ls(folders, flags);
    free_l(folders);
}