/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_vm.h"
#include "../include/my.h"
#include "../include/op.h"
#include "../include/lib.h"

champ_t *init_champ(void)
{
    champ_t *champ = malloc(sizeof(champ_t));

    champ->name = NULL;
    champ->magic = 0;
    champ->number = 0;
    champ->comment = NULL;
    champ->instruction = NULL;
    return (champ);
}

int my_nbrlen(int nbr)
{
    int length = 0;

    for (; nbr > 0; length++)
        nbr = nbr / 10;
    return (length);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    int b = i + 1;
    char c;
    int j = 0;

    while (j < i) {
        c = str[j];
        str[j] = str[i];
        str[i] = c;
        i--;
        j++;
    }
    str[b] = '\0';
    return (str);
}

char *to_binary(int the)
{
    int length = my_nbrlen(the);
    char hexaresult[length];
    char *str;
    int b = 0;

    for (; the > 0; b++) {
        hexaresult[b] = (the % 2) + 48;
        the = the / 2;
    }
    hexaresult[b] = '\0';
    str = my_revstr(hexaresult);
    return (str);
}