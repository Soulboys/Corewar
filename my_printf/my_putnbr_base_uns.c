/*
** EPITECH PROJECT, 2018
** my_putnbr_base_uns.c
** File description:
** my_putnbr_base_uns.c
*/

#include "../include/my_printf.h"

unsigned int my_putnbr_base_uns(unsigned int nbr, char *base)
{
    unsigned int size_base = 0;
    unsigned int nbr_final[100];
    int	i = 0;

    while (base[size_base])
        size_base++;
    while (nbr)
    {
        nbr_final[i] = nbr % size_base;
        nbr = nbr / size_base;
        i++;
    }
    while (--i >= 0)
    my_putchar(base[nbr_final[i]]);
    return (0);
}
