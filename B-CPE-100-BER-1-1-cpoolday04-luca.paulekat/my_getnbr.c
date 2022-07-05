/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** returns a number, sent to the function as a string
*/

int my_getnbr(char const *str)
{
    long n = 0;
    int l = my_strlen(str);
    int counter = check_neg_numbers(str);
    int x = check_non_int(str);

    while (x < l){
        if (str[x] != '\0' && !(str[x] < 48 || str[x] > 57)){
            n = inc_n(n, str, x);
            x += 1;
        } else
            x = l;
    }
    if (counter % 2 != 0)
        n *= -1;
    return (n);
}

int check_non_int(char *str)
{
    int i = 0;
    int c = 0;

    while (str[i] == '-' || str[i] == '+'){
        c += 1;
        i += 1;
    }
    return (c);
}

int check_neg_numbers(char *str)
{
    int i = 0;
    int counter = 0;

    while (str[i] == '-' || str[i] == '+'){
        if (str[i] == '-')
            counter++;
        i += 1;
    }
    return (counter);
}

int inc_n(long n, char *str, int x)
{
    int i = 0;
    int counter = check_neg_numbers(str);

    n *= 10;
    n = n + (str[x] - 48);
    if (n > 2147483647 && counter % 2 == 0){
        str[x + 1] = '\0';
        n = 0;
    } else if (n > 2147483648 && counter % 2 != 0){
        str[x + 1] = '\0';
        n = 0;
    }
    i = n;
    return (i);
}
