/*
** EPITECH PROJECT, 2018
** math.c
** File description:
** math function
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    result = nb * my_compute_power_rec(nb, p - 1);
    return (result);
}

int my_compute_square_root(int nb)
{
    int i = 1;

    for (; i * i < nb; i++) {
        if (i * i > nb)
            return (i - 1);
    }
    return (i);
}