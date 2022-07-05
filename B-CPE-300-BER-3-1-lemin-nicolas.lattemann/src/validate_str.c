/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <lemin.h>

int c_ant(char **str)
{
    int j = comments_before_ants(str);

    for (int i = 0; str[j][i] != '\0'; i++)
        if (!(str[j][i] >= 48 && str[j][i] <= 57))
            return 1;
    return 0;
}

void count_special_rooms(char **str, int i, int *n)
{
    if (my_strcmp(str[i], "##start") == 0)
        n[0] += 1;
    if (my_strcmp(str[i], "##end") == 0)
        n[1] += 1;
}

int check_copies(list_t *validation)
{
    char **comp = validation != NULL ? validation->item : NULL;
    char **tmp;
    list_t *cpy = validation;

    if (validation == NULL)
        return 0;
    while (validation->next != NULL && validation->next->item != NULL) {
        tmp = validation->next->item;
        if (tmp[0][0] == '\0')
            break;
        if (tmp[0] == NULL || tmp[1] == NULL || tmp[2] == NULL ||
            comp[0] == NULL || comp[1] == NULL || comp[2] == NULL)
            return 1;
        if (my_strcmp(tmp[0], comp[0]) == 0 || (my_strcmp(tmp[1], \
            comp[1]) == 0 && my_strcmp(tmp[2], comp[2]) == 0))
            return 1;
        else
            validation = validation->next;
    }
    return (check_copies(cpy->next));
}

int finish_valdiation(int *n, list_t *validation)
{
    n[3] = check_copies(to_start(&validation));
    free_list_validation(to_start(&validation));
    if (n[0] == 1 && n[1] == 1)
        return 0;
    else
        return 2;
}

int validate_str(char **str)
{
    int i = comments_before_ants(str) + 1;
    int n[4] = {0, 0, 0, 0};
    char **tmp;
    list_t *validation = NULL;
    int l = 0;

    for (; str[i] != NULL &&
        (includes(str[i], '-') == 0 || str[i][0] == '#'); i += 1) {
        count_special_rooms(str, i, n);
        if (str[i][0] == '#')
            continue;
        tmp = split_string(str[i], ' ');
        append_item(&validation, tmp);
        l = 1;
    }
    if (finish_valdiation(n, validation) == 2)
        return 2;
    n[2] = c_ant(str) == 0 && !(n[3] == 1) || l == 0 ? 0 : 1;
    return n[2];
}
