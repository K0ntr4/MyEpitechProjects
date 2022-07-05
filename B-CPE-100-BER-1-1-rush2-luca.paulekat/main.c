/*
** EPITECH PROJECT, 2021
** MAIN
** File description:
** desc
*/

#include "my.h"
#include "header.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    letter *data_array = generate_data_array();

    if (argc < 3) {
        my_puterror("84");
        return 84;
    }
    count_letters(argv[1], data_array);
    show_results(argc, argv, data_array);
    predict_lang(data_array);
    free(data_array);
    return 0;
}
