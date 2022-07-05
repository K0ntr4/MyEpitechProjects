/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** returns the smallest prime number greater/equal to the number given
*/

int my_find_prime_sup(int nb)
{
    int i = 0;
    int res;

    res = my_is_prime(nb);
    if (res == 1)
        return (nb);
    if (res == 0)
        my_find_prime_sup(nb + 1);
}
