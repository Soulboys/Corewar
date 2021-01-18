/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"
#include "lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static int get_nb_of_line(char *str, char var)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++)
        size += (str[i] == var) ? 1: 0;
    return (size + 1);
}

char *my_malloc_array(char *str, char *array, char var, int counter)
{
    for (; str[counter] != var && str[counter]; counter++);
    array = malloc(sizeof(char) * (counter + 1));
    return (array);
}

char **str_to_array(char *str, char var)
{
    int size = get_nb_of_line(str, var);
    char **array = malloc(sizeof(char *) * (size + 1));
    int line = 0;
    int character = 0;

    if (!str)
        return (NULL);
    for (int i = 0; i < size + 1; i++)
        array[i] = NULL;
    array[line] = my_malloc_array(str, array[line], var, 0);
    for (int i = 0; str[i]; i++, character++) {
        if (str[i] == var) {
            array[line][character] = '\0';
            line++;
            character = -1;
            array[line] = my_malloc_array(str, array[line], var, i + 1);
        } else
            array[line][character] = str[i];
    }
    array[line][character] = '\0';
    return (array);
}

char *my_strcat(char *to_join, char *str)
{
    char *new = NULL;
    int i = 0;
    int j = 0;

    if (!to_join)
        return (str);
    new = malloc(sizeof(char) * (my_strlen(to_join) + my_strlen(str) + 3));
    if (!new)
        return (NULL);
    if (str)
        for (; str[i]; i++)
            new[i] = str[i];
    for (; to_join[j]; j++)
        new[i + j] = to_join[j];
    new[i + j] = '\0';
    return (new);
}

char **read_map(char *str)
{
    int size = 0;
    int readed = 0;
    char *line = NULL;
    size_t len = 0;
    char *save = NULL;
    char **map_tab = NULL;
    FILE *fd = fopen(str, "r+");

    if (fd == NULL)
        return (NULL);
    for (int i = 0; (readed = getline(&line, &len, fd)) >= 0; i++, size++) {
        line[readed] = '\0';
        save = my_strcat(line, save);
    }
    save[my_strlen(save)] = '\0';
    map_tab = str_to_array(save, '\n');
    fclose(fd);
    free(save);
    free(line);
    return (map_tab);
}

