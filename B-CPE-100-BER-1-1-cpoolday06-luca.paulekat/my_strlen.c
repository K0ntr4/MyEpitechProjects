/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** returns the number of characters
*/

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0'){
        length += 1;
    }
    return (length);
}
