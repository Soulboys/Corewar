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

char *trad_comment(link_t *new)
{
    int size = count_size(new);
    char *comment = malloc(sizeof(char) * size + 1);
    int i = 1;
    int z = 0;

    for (; new->file_core[i] != 0 ; i++);
    for (; new->file_core[i] == 0 ; i++);
    for (; new->file_core[i]; i++, z++)
            comment[z] = new->file_core[i];
    comment[size] = 0;
    return (comment);
}

int count_action(link_t *new)
{
    int i = 1;

    for (; new->file_core[i] != 0 ; i++);
    for (; new->file_core[i] == 0 ; i++);
    for (; new->file_core[i] != 0 ; i++);
    for (; new->file_core[i] == 0 ; i++);
    i = new->full_size - i;
    return (i);
}

unsigned char **trad_action(link_t *new)
{
    int nb_action = count_action(new);
    unsigned char **action_arr =
    malloc(sizeof(unsigned char *) * (nb_action) + 1);
    int i = 1;

    for (int h = 0; h < nb_action ; h++)
        action_arr[h] = malloc(sizeof(unsigned char) * 10);
    for (; new->file_core[i] != 0 ; i++);
    for (; new->file_core[i] == 0 ; i++);
    for (; new->file_core[i] != 0 ; i++);
    for (; new->file_core[i] == 0 ; i++);
    for (int b = 0; b < nb_action ; b++, i++)
        action_arr[b][0] = new->file_core[i];
    return (action_arr);
}

int count_link_number(link_t *list)
{
    link_t *tmp = list;
    int number = 0;

    for (; list->back != NULL ; list = list->back);
    for (; list != NULL ; list = list->next)
        number++;
    list = tmp;
    return (number);
}

unsigned char *add_player_to_map(link_t *list, unsigned char *map)
{
    int index_a [2] = {0, 0};
    int nb_player = count_link_number(list);
    int index = 0;
    int quart = MEM_SIZE / nb_player;

    for (; list->back != NULL ; list = list->back);
    for (; list != NULL ; list = list->next) {
        index_a[1] = count_action(list);
        if (list->place > 0)
            index = list->place;
        for (int i = 0 ; i < index_a[1] ; i++) {
            if (map[index] != 0)
                return (NULL);
            map[index] = list->action[i][0];
            index++;
        }
        index_a[0] += quart;
        index = index_a[0];
    }
    return (map);
}