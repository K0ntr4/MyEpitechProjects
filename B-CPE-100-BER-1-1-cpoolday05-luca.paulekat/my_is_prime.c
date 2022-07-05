/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** returns 1 if the number is prime and 0 if not
*/

int my_is_prime(int nb)
{
    int res = get_square_root(nb);
    int i = 2;

    if (nb <= 1)
        return (0);
    while (i <= res){
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int get_square_root(int nb)
{
    int i = 1;
    int n = 1;

    if (nb <= 0)
        return (0);
    while (n <= nb){
        i++;
        n = i * i;
        }
    return (i - 1);
}
