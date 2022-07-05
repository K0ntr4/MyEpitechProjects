/*
** EPITECH PROJECT, 2021
** my_compute_power
** File description:
** returns the first argument raised to the power p
*/

int my_compute_power_it(int nb , int p)
{
    int i = 1;
    long n = nb;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    while (i < p){
        n = n * (long)nb;
        i++;
    }
    if (n > 2147483647)
        return (0);
    else
        return (n);
}
