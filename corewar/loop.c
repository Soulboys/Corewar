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
#include "../include/lib.h"
#include "../include/my_vm.h"
#include "../include/my.h"
#include "../include/op.h"

int disp_in_hexadecimal(int the)
{
    char *arr = "0123456789ABCDEF";
    int length = my_nbrlen(the);
    char hexaresult[length];
    char *str;
    int b = 0;

    for (; the > 0; b++) {
        hexaresult[b] = arr[(the % 16)];
        the = the / 16;
    }
    hexaresult[b] = '\0';
    str = my_revstr(hexaresult);
    my_putstr(str);
    return (0);
}

int check_list_loop(link_t *list)
{
    link_t *tmp = list;
    int check = 1;

    for (; list->back != NULL ; list = list->back);
    for (; list->next != NULL ; list = list->next) {
        if (list->status > 0)
            check = 0;
    }
    list = tmp;
    return (check);
}

int disp_first_part(int i, int *line)
{
    *line += 1;
    write(1, "\n", 1);
    disp_in_hexadecimal(i);
    if (*line < 8)
        my_printf("  ");
    else if (*line < 128)
        my_printf(" ");
    my_printf(" :");
    return (0);
}

void disp_map(link_t *list)
{
    int b = 0;
    int line = 0;
    unsigned char *map = malloc(sizeof(char) * MEM_SIZE);

    for (int z = 0 ; z < MEM_SIZE ; z++)
        map[z] = 0;
    map = add_player_to_map(list, map);
    if (map == NULL)
        return;
    write(1, "\n0    :", 7);
    for (int i = 0 ; i < MEM_SIZE ; i++, b++) {
        if (b == 32)
            b = disp_first_part(i, &line);
        my_printf(" ");
        if (map[i] < 16)
            my_printf("0");
        if (map[i] < 1)
            my_printf("0");
        disp_in_hexadecimal(map[i]);
    }
}

void loop(link_t *list, int nb)
{
    static int turn = 0;
    int turn_max = 3000;

    for (; turn < turn_max ;) {
        if (nb > 0 && turn == nb) {
            disp_map(list);
        }
        if (list->next != NULL) {
            list = list->next;
        } else {
            for (; list->back != NULL ; list = list->back);
        }
        if (list->status >= 1)
            turn = disp_player(list, turn);
        else if (list->status < 1)
            turn--;
        if (check_list_loop(list) == 1)
            break;
    }
    my_printf("\nPlayer %d (%s) has won\n", list->number, list->name);
}
