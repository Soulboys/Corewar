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

int to_name(link_t *link)
{
    int size = 4;

    for (; link->file_core[size] != 0 ; size++);
    size -= 3;
    return (size);
}

int check_the_magic(link_t *link)
{
    int *check_magic = malloc(sizeof(int) * 4);

    check_magic[0] = 00;
    check_magic[1] = 234;
    check_magic[2] = 131;
    check_magic[3] = 243;
    for (int i = 0 ; i < 4 ; i++)
        if (link->magic_number[i] != check_magic[i])
            return (1);
    return (0);
}

int *trad_magic(link_t *link)
{
    int *magic_nb = malloc(sizeof(int) * 4);

    for (int index = 0 ; index < 4 ; index++)
        magic_nb[index] = link->file_core[index];
    return (magic_nb);
}

char *trad_name(link_t *link)
{
    int size = to_name(link);
    char *name = malloc(sizeof(char) * size + 1);
    int count = 4;
    int b = 4;

    for (int i = 0; i < count ; i++, b++)
        name[i] = link->file_core[b];
    name[size] = 0;
    return (name);
}

int count_size(link_t *new)
{
    int count = 1;
    int i = 1;

    for (; new->file_core[i] != 0 ; i++);
    for (; new->file_core[i] == 0 ; i++);
    for (; new->file_core[i] ; count++, i++);
    return (count);
}