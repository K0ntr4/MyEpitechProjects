/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** returns the square root of the number given as an argument
*/

int my_compute_square_root(int nb)
{
    int i = 1;
    int n = 1;

    if (nb <= 0)
        return (0);
    while (n <= nb){
        if (n == nb)
            return (i);
        else {
            i++;
            n = i * i;
        }
    }
    return (0);
}
