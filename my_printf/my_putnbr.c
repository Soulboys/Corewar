/*
** EPITECH PROJECT, 2018
** my_putnbr.c
** File description:
** my_putnbr
*/

#include "../include/my_printf.h"

int my_putnbr(int nb)
{
    int n;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            n = (nb % 10);
        nb = (nb - n) / 10;
        my_putnbr(nb);
        my_putchar(48 + n);
        }
        else
            my_putchar(48 + nb % 10);
    }
    return (0);
}
