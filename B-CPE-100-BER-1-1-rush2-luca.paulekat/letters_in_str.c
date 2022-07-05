/*
** EPITECH PROJECT, 2021
** my_count_letter
** File description:
** counts the letters of a given string
*/

int letters_in_str(char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
            counter++;
    }
    return (counter);
}
