/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <malloc.h>
#include <dirent.h>
#include <sys/stat.h>
#include "my.h"

int dir_not_found(char *path)
{
    my_puterror(path);
    my_puterror(": No such file or directory.");
    my_puterror("\n");
    return 84;
}

int is_not_dir(char *path)
{
    my_puterror(path);
    my_puterror(": Not a directory.");
    my_puterror("\n");
    return 84;
}

int is_directory(char *path)
{
    struct stat *statbuf = malloc(sizeof(struct stat));
    int is_dir = 0;

    stat(path, statbuf);
    if (S_ISDIR(statbuf->st_mode))
        is_dir = 1;
    free(statbuf);
    return is_dir;
}

int verify_directory(char *full_path, char *path)
{
    DIR *directory = NULL;

    if (!is_directory(full_path))
        return is_not_dir(path);
    directory = opendir(full_path);
    if (!directory)
        return dir_not_found(path);
    closedir(directory);
    return 0;
}
