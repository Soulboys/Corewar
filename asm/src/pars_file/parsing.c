/*
** EPITECH PROJECT, 2018
** duo_stumper_4_2018
** File description:
** main.c
*/

#include "op.h"
#include "../../include/my.h"
#include "lib.h"

void create_file_cor(char *nam, file_t *info)
{
    int j = 0;
    int i = 0;

    for (; nam[i]; i++);
    for (; nam[i - 1] != '/' && nam[i - 1]; i--, j++);
    info->name = malloc(sizeof(char) * j + 1);
    for (int k = 0; nam[i] != '.' && nam[i]; i++, k++) {
        info->name[k] = nam[i];
        info->name[k + 1] = '\0';
    }
    info->name = my_strcat(".cor", info->name);
    info->fd = open(info->name, O_CREAT | O_RDWR, 0777);
}

int check_err(char **file)
{
    return(0);
}

int parsing(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    for (int i = 0; argv[1][i]; i++)
        if (argv[1][i] == '.' && argv[1][i + 1] == 's')
        return (1);
    return (0);
}