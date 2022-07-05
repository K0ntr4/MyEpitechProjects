/*
** EPITECH PROJECT, 2021
** my_compute_factorial_it
** File description:
** returns the factorial of the number given as a parameter
*/

int my_compute_factorial_it(int nb)
{
    int i = 1;
    long n = 1;

    if (nb < 0)
        return (0);
    while (i <= nb){
        n = i * n;
        i++;
        if (n > 2147483647){
            return (0);
        }
    }
    return (n);
}
