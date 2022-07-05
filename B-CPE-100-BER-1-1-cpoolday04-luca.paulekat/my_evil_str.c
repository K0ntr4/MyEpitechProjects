/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** returns the number of characters
*/

char * my_evil_str(char *str)
{
    int length = 0;
    char arr = *str;
    int i = 0;
    char content1;
    char content2;
    int l = my_strlen(str);

    while (i < l){
        content1 = str[i];
        content2 = str[l - 1];
        str[i] = content2;
        str[l - 1] = content1;
        i++;
        l--;
    }
    return (str);
}
