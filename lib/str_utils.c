/*
** EPITECH PROJECT, 2018
** str_utils.c
** File description:
** utils for str
*/

#include "lib.h"
#include <stdlib.h>
#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] != 0; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

int my_strlen(char const *str)
{
    if (!str)
        return (0);
    for (int i = 0; str[i] != '\0'; i += 1)
        if (str[i + 1] == '\0')
            return (i + 1);
    return (0);
}

char *my_revstr(char *str)
{
    int x = my_strlen(str) - 1;
    char y;

    for (int i = 0; i < x; i++, x--) {
        y = str[i];
        str[i] = str[x];
        str[x] = y;
    }
    return (str);
}

int my_search_word(char *str, char *word)
{
    char **arg = NULL;
    int check = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == ' ')
            check++;
    if (check >= 1) {
        arg = str_to_array(str, ' ');
        for (int i = 0; arg[i] != NULL; i++)
            if (my_strcmp2(arg[i], word) == 1)
                return (1);
        for (int i = 0; arg[i]; i++)
            free(arg[i]);
        free(arg);
    } else
        return (my_strcmp2(str, word));
    return (0);
}

int my_strcmp(char *s1, char *s2)
{
    int j = 0;
    int tmp = 0;
    int tmp2 = my_strlen(s2);

    for (int i = 0; s1[i]; i++) {
        if (s1[i] == s2[j]) {
            tmp++;
            j++;
        } else {
            j = 0;
            tmp = 0;
        }
        if (tmp == tmp2)
            return (1);
        }
    return (0);
}