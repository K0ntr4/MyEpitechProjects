/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include <lemin.h>

int check_rooms(char **str)
{
    if (str[1] == NULL)
        return 1;
    if (str[2] == NULL)
        return 1;
    for (int i = 0; str[1][i] != '\0'; i++) {
        if (!(str[1][i] >= 48 && str[1][i] <= 57))
            return 1;
    }
    for (int i = 0; str[2][i] != '\0'; i++) {
        if (!(str[2][i] >= 48 && str[2][i] <= 57))
            return 1;
    }
    return 0;
}

void get_special(room_t *link, char **str, int i)
{
    if (my_strcmp(str[i - comments_after_command(str, i)], "##start") == 0) {
        link->special = START_ROOM;
    } else if (my_strcmp(str[i - 1], "##end") == 0) {
        link->special = END_ROOM;
    } else {
        link->special = DEFAULT_ROOM;
    }
}

room_t *get_links(char **str, int *n, room_t **links)
{
    char **tmp;

    for (; str[n[1]] != NULL && includes(str[n[1]], '-') != 0; n[1] += 1) {
        if (str[n[1]][0] == '#')
            continue;
        tmp = split_string(str[n[1]], '-');
        if (tmp[1] == NULL)
            return returning_start_room(links);
        get_linking_rooms(links, tmp, n);
        if (n[2] == n[3])
            continue;
        if (links[n[2]] == NULL || links[n[3]] == NULL)
            return returning_start_room(links);
        connect_links(links[n[2]], links[n[3]], 0);
    }
    return returning_start_room(links);
}

int get_rooms(room_t **links, int *n, char **str, int *n_room)
{
    char **tmp;
    int cords[2];

    for (; str[n[1]] != NULL &&
        (includes(str[n[1]], '-') == 0 || str[n[1]][0] == '#'); n[1] += 1) {
        if (str[n[1]][0] == '#')
            continue;
        tmp = split_string(str[n[1]], ' ');
        if (check_rooms(tmp) != 0)
            return 1;
        links[n[0]] = create_link(my_strdup(tmp[0]), *n_room);
        cords[0] = my_getnbr(tmp[1]);
        cords[1] = my_getnbr(tmp[2]);
        links[n[0]]->coordinates = cords;
        get_special(links[n[0]], str, n[1]);
        n[0] += 1;
        *n_room += 1;
    }
    return 0;
}

room_t *parse_input(char **str, int *n_room)
{
    room_t *links[arr_length((const char **) str) + 1];
    int n[4] = {0, comments_before_ants(str) + 1, 0, 0};

    if (get_rooms(links, n, str, n_room) == 1)
        return NULL;
    links[n[0]] = NULL;
    return get_links(str, n, links);
}
