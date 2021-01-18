/*
** EPITECH PROJECT, 2018
** CPE_get_next_line_2018
** File description:
** get_next_line.c
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

char *add_to_str(char *to_join, char *str)
{
    char *new = NULL;
    int i = 0;
    int j = 0;

    if (!to_join)
        return (NULL);
    new = malloc(sizeof(char) * (my_strlen(to_join) + my_strlen(str) + 1));
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

char *get_file(int fd)
{
    char *file = NULL;
    char *tmp = NULL;
    char buffer[READ_SIZE + 1];
    int readed = 1;

    while (readed > 0) {
        readed = read(fd, buffer, READ_SIZE);
        printf("\033[31;1mREADED\033[0m\n");
        buffer[readed] = '\0';
        tmp = file;
        file = add_to_str(buffer, tmp);
        free(tmp);
        if (fd == 0 || my_strlen(buffer) < READ_SIZE)
            return (file);
    }
    return (file);
}

char *get_the_line(char *file, int *index_line)
{
    char *line = malloc(sizeof(char) * (my_strlen(file) + 1));
    int index = 0;

    for (; file[*index_line] && file[*index_line] != '\n'; (*index_line)++,
        index++)
        line[index] = file[*index_line];
    line[index] = '\0';
    (*index_line)++;
    return (line);
}

char *gnl(int fd)
{
    static int index = 0;
    static char *file = NULL;
    char *line = NULL;

    if (fd == -1 || !READ_SIZE || (my_strlen(file) <= index && index > 0)) {
        if (file)
            free(file);
        return (NULL);
    }
    if (!index) {
        file = get_file(fd);
        if (!file)
            return (NULL);
    }
    line = get_the_line(file, &index);
    return (line);
}