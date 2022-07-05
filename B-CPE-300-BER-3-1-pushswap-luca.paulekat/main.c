/*
** EPITECH PROJECT, 2021
** pushswap
** File description:
** desc
*/
#include "mylist.h"
#include "my.h"

int main(int argc, char **argv)
{
    linked_list_t *tmp = my_params_to_list(argc, argv);
    linked_list_t *tmp2 = new_elem(my_strdup(" "));
    char *new_str = malloc(sizeof(char) * 510);
    linked_list_t *print_list = new_elem(new_str);
    int n[6] = {0, 0, 0, 0, 0, 0};

    new_str[0] = '\0';
    if (check_list(tmp, -1) == 0) {
        my_putstr("\n");
        free_l(tmp);
        free_l(tmp2);
        return 0;
    }
    quicksort_list(&tmp, &tmp2, n, print_list);
    to_start(&tmp);
    if (my_strcmp(tmp->data, " ") == 0)
        last_move(&tmp, tmp2, "b", print_list);
    print_print_list(print_list);
    free(print_list);
    free_l(tmp);
}
