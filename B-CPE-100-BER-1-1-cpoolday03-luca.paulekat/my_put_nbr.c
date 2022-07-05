/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** displays the number given as a parameter
*/

int my_put_nbr(int nb)
{
    int size = 10;

    if (nb < 0){
        nb = output('-', nb);
    }
    if (nb > 9){
        while (nb / size >= 10){
            size *= 10;
        }
        output(nb / size + 48);
        while (size > 10){
            size /= 10;
            output((nb / size) % 10 + 48);
            }
        output(nb % size + 48);
    }
    else {
        output(nb + 48);
    }
    return (1);
}

int output(int o, int nb)
{
    if (nb < 0){
        nb *= -1;
    }
    write( 1, &o, 1);
    return (nb);
}
