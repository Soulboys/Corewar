/*
** EPITECH PROJECT, 2018
** duo_stumper_4_2018
** File description:
** main.c
*/

#include "op.h"
#include "../../include/my.h"
#include "lib.h"

int my_strcmp2(char *s1, char *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return (0);
    return (my_strcmp(s1, s2));
}

void swap_int(void *val)
{
    unsigned char tmp;
    bytesint *swp = (bytesint *)val;

    tmp = (*swp)[0];
    (*swp)[0] = (*swp)[3];
    (*swp)[3] = tmp;
    tmp = (*swp)[1];
    (*swp)[1] = (*swp)[2];
    (*swp)[2] = tmp;
}

void swap_short(void *val)
{
    unsigned char tmp;
    bytes_two_int *swp = (bytes_two_int *)val;

    tmp = (*swp)[0];
    (*swp)[0] = (*swp)[1];
    (*swp)[1] = tmp;
}

char *rac_str(char *src)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * my_strlen(src) + 2);

    if (src[0] == '\0')
        return (NULL);
    for (; src[i] != ' ' && src[i]; i++);
    for (; src[i + 1] != '\0' && src[i]; i++, j++) {
        str[j] = src[i];
    }
    str[j] = src[i];
    str[j + 1] = '\0';
    return (str);
}

char *clean_str(char *src)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * my_strlen(src) + 2);

    if (my_strlen(src) <= 2)
        return (src);
    i++;
    for (; src[i + 1] != '\0' && src[i]; i++, j++)
        str[j] = src[i];
    str[j] = src[i];
    str[j + 1] = '\0';
    return (str);
}