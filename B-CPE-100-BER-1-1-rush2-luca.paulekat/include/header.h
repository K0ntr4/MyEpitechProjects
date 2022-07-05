/*
** EPITECH PROJECT, 2021
** HEADER
** File description:
** desc
*/

#ifndef HEADER_H_
    #define HEADER_H_
struct letter {
    unsigned char character;
    unsigned int occurences;
    float frequency;
    short counted;
};

typedef struct letter letter;

int letters_in_str(char *str);

int count_letters(char *string, letter *data_array);

void show_data_array(letter *data_array);

struct letter *generate_data_array(void);

char normalize(char c);

void show_results(char argc, char **argv, letter *data_array);

int predict_lang(letter *data_array);

#endif
