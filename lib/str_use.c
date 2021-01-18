/*
** EPITECH PROJECT, 2018
** number.c
** File description:
** function returns a value
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

void swap(char **s1, char **s2)
{
    char *str = *s1;

    *s1 = *s2;
    *s2 = str;
}