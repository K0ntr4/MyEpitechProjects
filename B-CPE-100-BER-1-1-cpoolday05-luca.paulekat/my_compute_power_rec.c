/*
** EPITECH PROJECT, 2021
** my_compute_power_rec
** File description:
** returns the first argument raised to the power p
*/

int my_compute_power_rec(int nb , int p)
{
    int i = 1;
    int n = nb;
    long res;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    res = ((long)my_compute_power_rec(nb, p - 1) * (long)nb);
    if (res > 2147483647)
        return (0);
    else
        return (res);
}
