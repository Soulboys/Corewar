/*
** EPITECH PROJECT, 2018
** my_putnbr_uns.c
** File description:
** my_putnbr_uns.c
*/

#include "../include/my_printf.h"

unsigned int my_putnbr_uns(unsigned int nb)
{
    unsigned int n;

    if (nb >= 10) {
        n = (nb % 10);
    nb = (nb - n) / 10;
    my_putnbr(nb);
    my_putchar(48 + n);
    }
    else
        my_putchar(48 + nb % 10);
    return (0);
}
