/*
** EPITECH PROJECT, 2018
** my_printf2.c
** File description:
** my_printf2.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my_printf.h"

int pointer_adress(unsigned long nb)
{
    char *base = "0123456789abcdef";
    unsigned int size_base = 0;
    unsigned int nb_final[100];
    int	i = 0;

    my_putstr("0x");
    while (base[size_base])
        size_base++;
    while (nb)
    {
        nb_final[i] = nb % size_base;
        nb = nb / size_base;
        i++;
    }
    while (--i >= 0)
    my_putchar(base[nb_final[i]]);
    return (0);
}

unsigned int decimal_to_hexadecimalX(unsigned int nb)
{
    unsigned int result = nb;
    int i = 0;
    int reste = 0;
    char *str = malloc(40);

    while (result != 0) {
        result = (nb / 16);
        reste = nb - (16 * result);
        nb = result;
        if (result > 9)
            result = result + 48;
        str[i] = reste + 55;
        i++;
    }
    my_revstr(str);
    my_putstr(str);
    free(str);
    return (result);
}

unsigned int decimal_to_hexadecimalx(unsigned int nb)
{
    unsigned int result = nb;
    int i = 0;
    int reste = 0;
    char *str = malloc(40);

    while (result != 0) {
        result = (nb / 16);
        reste = nb - (16 * result);
        nb = result;
        if (result > 9)
            result = result + 48;
        str[i] = reste + 87;
        i++;
    }
    my_revstr(str);
    my_putstr(str);
    free(str);
    return (result);
}

unsigned int decimal_to_octal(unsigned int nb)
{
    unsigned int result = nb;
    int i = 0;
    int reste = 0;
    char *str = malloc(my_nbrlen(nb) + 1);

    while (result != 0) {
        result = (nb / 8);
        reste = nb - (8 * result);
        nb = result;
        str[i] = reste + 48;
        i++;
    }
    my_revstr(str);
    my_putstr(str);
    free(str);
    return (result);
}

unsigned int decimal_to_base(unsigned int nb)
{
    unsigned int result = nb;
    int i = 0;
    int reste = 0;
    char *str = malloc(40);

    while (result != 0) {
        result = (nb / 2);
        reste = nb - (2 * result);
        nb = result;
        str[i] = reste + 48;
        i++;
    }
    my_revstr(str);
    my_putstr(str);
    free(str);
    return (result);
}
