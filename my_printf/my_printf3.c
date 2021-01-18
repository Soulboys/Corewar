/*
** EPITECH PROJECT, 2018
** my_printf3.c
** File description:
** my_printf3.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my_printf.h"

void put_zeros(int j)
{
    int i = 0;

    my_putchar('\\');
    i = decimal_to_octal(j);
    if (j < 100)
        my_putchar ('0');
    if (j < 10)
        my_putchar ('0');
    my_putnbr(i);
}

int case_S(char *s)
{
    int i = 0;
    int j = 0;

    while (s[i] != '\0') {
        if (s[i] >= 32)
            my_putchar(s[i]);
        else {
            j = s[i];
            put_zeros(j);
        }
        i++;
    }
    return (0);
}
