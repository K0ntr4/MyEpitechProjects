/*
** EPITECH PROJECT, 2021
** Project
** File description:
** desc
*/

#include "my.h"

int is_number_str(const char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!(48 <= str[i] && str[i] <= 57))
            return 0;
    }
    return 1;
}

int is_room_start(const char *str)
{
    int number_count = 0;
    int space_count = 0;
    int space_count_buf = -1;
    int is_command = !my_strcmp("##start", str) || !my_strcmp("##end", str);

    for (int i = 0; str[i]; i++) {
        if (!(48 <= str[i] && str[i] <= 57) && str[i] != ' ' && !is_command)
            return 0;
        if (48 <= str[i] && str[i] <= 57 && space_count != space_count_buf) {
            number_count++;
            space_count_buf = space_count;
        }
        if (str[i] == ' ')
            space_count++;
    }
    return (number_count == 3 && space_count == 2) || is_command;
}

int is_tunnel_start(const char *str)
{
    int number_count = 0;
    int dash_count = 0;
    int dash_count_buf = -1;

    for (int i = 0; str[i]; i++) {
        if (!(48 <= str[i] && str[i] <= 57) && str[i] != '-')
            return 0;
        if (48 <= str[i] && str[i] <= 57 && dash_count != dash_count_buf) {
            number_count++;
            dash_count_buf = dash_count;
        }
        if (str[i] == '-')
            dash_count++;
    }
    return number_count == 2 && dash_count == 1;
}

int is_comment(const char *str)
{
    return str[0] == '#' && str[1] != '#';
}

void show_input(const char **input)
{
    int printed_rooms = 0;
    int printed_ants = 0;
    int printed_tunnels = 0;

    for (int i = 0; input[i]; i++) {
        if (is_comment(input[i]) || !my_strlen(input[i]))
            continue;
        if (!printed_ants && (printed_ants = is_number_str(input[i])))
            my_putstr("#number_of_ants\n");
        if (!printed_rooms && (printed_rooms = is_room_start(input[i])))
            my_putstr("#rooms\n");
        if (!printed_tunnels && (printed_tunnels = is_tunnel_start(input[i])))
            my_putstr("#tunnels\n");
        my_putstr(input[i]);
        my_putchar('\n');
    }
}
