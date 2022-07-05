/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** desc
*/
#include "my.h"
#include "myls.h"

char get_file_type(struct stat stat)
{
    if (S_ISDIR(stat.st_mode))
        return 'd';
    if (S_ISCHR(stat.st_mode))
        return 'c';
    if (S_ISBLK(stat.st_mode))
        return 'b';
    if (S_ISFIFO(stat.st_mode))
        return 'p';
    if (S_ISLNK(stat.st_mode))
        return 'l';
    if (S_ISSOCK(stat.st_mode))
        return 's';
    if (S_ISREG(stat.st_mode))
        return '-';
}

void get_normed(struct stat stat, char *rights)
{
    rights[1] = stat.st_mode & S_IRUSR ? 'r' : '-';
    rights[2] = stat.st_mode & S_IWUSR ? 'w' : '-';
    rights[3] = stat.st_mode & S_IXUSR ? 'x' : '-';
    rights[4] = stat.st_mode & S_IRGRP ? 'r' : '-';
    rights[5] = stat.st_mode & S_IWGRP ? 'w' : '-';
}

char *get_rights(struct stat stat)
{
    char *rights = malloc(sizeof(char) * 11);

    rights[0] = get_file_type(stat);
    get_normed(stat, rights);
    if ((stat.st_mode & S_ISGID) && !(stat.st_mode & S_IXGRP))
        rights[6] = 'S';
    else if ((stat.st_mode & S_ISGID) && (stat.st_mode & S_IXGRP))
        rights[6] = 's';
    else
        rights[6] = stat.st_mode & S_IXGRP ? 'x' : '-';
    rights[7] = stat.st_mode & S_IROTH ? 'r' : '-';
    rights[8] = stat.st_mode & S_IWOTH ? 'w' : '-';
    if ((stat.st_mode & S_ISVTX) && !(stat.st_mode & S_IXOTH))
        rights[9] = 'T';
    else if ((stat.st_mode & S_ISVTX) && (stat.st_mode & S_IXOTH))
        rights[9] = 't';
    else
        rights[9] = stat.st_mode & S_IXOTH ? 'x' : '-';
    rights[10] = '\0';
    return rights;
}