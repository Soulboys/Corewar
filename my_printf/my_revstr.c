/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** my_revstr
*/

#include "../include/my_printf.h"

char *my_revstr(char *str)
{
    char swpchar;
    int i;
    int len;

    i = 0;
    len = my_strlen(str);
    if (len > 0)
        while (i < len / 2) {
            swpchar = str[i];
            str[i] = str[len - 1 - i];
            str[len - i - 1] = swpchar;
            i++;
        }
    return (str);
}
