/*
** EPITECH PROJECT, 2021
** my_ls
** File description:
** desc
*/
#include "my.h"
#include "myls.h"

int get_total(struct my_ls_l *folders)
{
    DIR *directory;
    struct dirent *dirp;
    struct stat info;
    char *filename;
    int total = 0;

    directory = opendir(folders->folder);
    if (directory == NULL)
        return 84;
    while ((dirp = readdir(directory)) != NULL) {
        if (dirp->d_name[0] != '.') {
            filename = malloc(sizeof(char) * (my_strlen(folders->folder) \
                + my_strlen(dirp->d_name)) + 2);
            my_strcpy(filename, folders->folder);
            filename = my_strcat(my_strcat(filename, "/\0"), dirp->d_name);
            lstat(filename, &info) == 0 ? total += info.st_blocks : 0;
        }
    }
    closedir(directory);
    return total;
}

void check_dir(struct my_ls_l *folders, struct my_ls_l *res, int *flags)
{
    char *filename;
    struct stat info;
    char *rights;

    if (res->flag_R != 1)
        return;
    filename = malloc(sizeof(char) * (my_strlen(folders->folder) \
        + my_strlen(res->folder)) + 2);
    my_strcpy(filename, folders->folder);
    filename = my_strcat(my_strcat(filename, "/\0"), res->folder);
    stat(filename, &info);
    rights = get_rights(info);
    if (rights[0] == 'd')
        append_item(&folders, filename, flags);
    free(rights);
}

void prints (struct stat info, struct passwd *uid, \
    struct group *gid, struct my_ls_l *res)
{
    char *rights;

    rights = get_rights(info);
    res->rights = rights;
    res->n_link = info.st_nlink;
    res->pw = uid->pw_name;
    res->gr = gid->gr_name;
    res->size = info.st_size;
    res->time = ctime(&info.st_mtime);
}

void get_l_infos(struct my_ls_l *folders, struct my_ls_l *res)
{
    char *filename;
    struct passwd *uid;
    struct group *gid;
    struct stat info;

    filename = malloc(sizeof(char) * (my_strlen(folders->folder) \
        + my_strlen(res->folder)) + 2);
    my_strcpy(filename, folders->folder);
    filename = my_strcat(my_strcat(filename, "/\0"), res->folder);
    stat(filename, &info);
    uid = getpwuid(info.st_uid);
    gid = getgrgid(info.st_gid);
    prints(info, uid, gid, res);
}

void my_lsl(struct my_ls_l *folders, struct my_ls_l *res, int *flags)
{
    char *filename;
    int total;

    total = get_total(folders);
    my_putstr("total ");
    my_put_nbr(total / 2);
    my_putchar('\n');
    to_start(&res);
    while (res && res->next) {
        get_l_infos(folders, res);
        check_dir(folders, res, flags);
        res = res->next;
    }
    get_l_infos(folders, res);
    check_dir(folders, res, flags);
}