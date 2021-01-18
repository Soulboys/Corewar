/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** my_putstr
*/

#include "../include/my_printf.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
