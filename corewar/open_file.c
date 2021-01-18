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

unsigned char *concat(unsigned char *str1, unsigned char *str2, int final_size,
int size)
{
    unsigned char *str = malloc(sizeof(unsigned char) * (final_size + 1));
    int count = 0;

    if (!str)
        return (NULL);
    for (; count < final_size - size; count++)
        str[count] = str1[count];
    for (int c = 0 ; c < size; c++, count++)
        str[count] = str2[c];
    str[count] = 0;
    return (str);
}

unsigned char *open_file_vm(char *file, link_t *new)
{
    int fd = open(file, O_RDONLY);
    unsigned char *buff = malloc(sizeof(unsigned char) * 4099);
    int size;
    unsigned char *final_buff = NULL;

    if (fd <= 0 || !buff)
        return (NULL);
    while (1) {
        size = read(fd, buff, 4098);
        if (size <= 0)
            return (NULL);
        new->full_size += size;
        final_buff = concat(final_buff, buff, new->full_size, size);
        if (size != 4098)
            break;
    }
    close(fd);
    return (final_buff);
}

int disp_player(link_t *list, int turn)
{
    static int a = 0;

    if (a == 1)
        my_printf("\n");
    a = 1;
    my_printf("Le joueur %d (%s) est en vie.", list->number, list->name);
    list->live += 1;
    if (list->live > NBR_LIVE)
        list->status -= CYCLE_DELTA;
    turn++;
    return (turn);
}