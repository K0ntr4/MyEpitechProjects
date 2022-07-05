/*
** EPITECH PROJECT, 2021
** my_compute_factorial_rec
** File description:
** returns the factorial of the number given as a parameter
*/

int my_compute_factorial_rec(int nb)
{
    long res;

    if (nb == 1 || nb == 0)
        return (1);
    if (nb < 0)
        return (0);
    res = ((long)nb * (long)my_compute_factorial_rec(nb - 1));
    if (res > 2147483647)
        return (0);
    else
        return (res);
}
