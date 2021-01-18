/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my_printf.h"

void switch4(char flag, va_list list)
{
    char *s;

    switch (flag) {
        case 's':
            s = va_arg(list, char *);
            my_putstr(s);
            break;
        case 'S':
            s = va_arg(list, char *);
            case_S(s);
            break;
    }
}

void switch3(char flag, va_list list)
{
    int i;
    unsigned int u;

    switch (flag) {;
        case 'o':
            u = va_arg(list, unsigned int);
            decimal_to_octal(u);
            break;
        case 'x':
            i = va_arg(list, int);
            decimal_to_hexadecimalx(i);
            break;
        case 'u':
            u = va_arg(list, unsigned int);
            my_putnbr_uns(u);
            break;
        case '%':
            my_putchar('%');
            break;
    }
    switch4(flag, list);
}

void switch2(char flag, va_list list)
{
    int i;
    unsigned int u;
    long long l;

    switch (flag) {
        case 'X':
            i = va_arg(list, int);
            decimal_to_hexadecimalX(i);
            break;
        case 'b':
            u = va_arg(list, unsigned int);
            decimal_to_base(u);
            break;
        case 'p':
            l = va_arg(list, long);
            pointer_adress(l);
        break;
    }
    switch3(flag, list);
}

void switch1(char flag, va_list list)
{
    int i;
    char c;

    switch (flag)
    {
        case 'd':
            i = va_arg(list, int);
            my_putnbr(i);
            break;
        case 'i':
            i = va_arg(list, int);
            my_putnbr(i);
            break;
        case 'c':
            c = va_arg(list, int);
            my_putchar(c);
            break;
    }
    switch2(flag, list);
}

int my_printf(char *str, ...)
{
    va_list list;
    char flag;
    int j;
    int count;

    va_start(list, str);
    for (j = 0; str[j] != '\0'; j++) {
        count = 0;
        if (str[j] == '%') {
            flag = str[j + 1];
            switch1(flag, list);
            j++;
            count = 1;
        }
        if (count != 1)
            my_putchar(str[j]);
    }
    va_end(list);
    return (0);
}
