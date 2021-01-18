/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** CPool_Day08_2018
*/

#include <stdarg.h>

#ifndef CPOOL_DAY08_2018_MY_H
#define CPOOL_DAY08_2018_MY_H

    unsigned int my_putnbr_base_uns(unsigned int nbr, char *base);
    unsigned int my_putnbr_uns(unsigned int nb);
    int my_putstr(char const *str);
    int my_printf2(char *str, ...);
    int my_printf3(char *str, ...);
    int my_printf(char *str, ...);
    char *my_revstr(char *str);
    int my_strlen(char *str);
    void my_putchar(char c);
    int my_nbrlen(int nbr);
    void verify(char flag);
    int my_putnbr(int nb);
    void switch1(char flag, va_list list);
    void switch2(char flag, va_list list);
    void switch3(char flag, va_list list);
    void switch4(char flag, va_list list);
    unsigned int decimal_to_octal(unsigned int d);
    unsigned int decimal_to_base(unsigned int d);
    unsigned int decimal_to_hexadecimalx(unsigned int d);
    unsigned int decimal_to_hexadecimalX(unsigned int d);
    int pointer_adress(unsigned long nb);
    void put_zeros(int j);
    int case_S(char *s);

#endif
