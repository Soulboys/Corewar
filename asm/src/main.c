/*
** EPITECH PROJECT, 2018
** duo_stumper_4_2018
** File description:
** main.c
*/

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "op.h"

int asm_start(int argc, char **argv)
{
    file_t *info = malloc(sizeof(file_t));
    header_t *head = {0, 0, 0, 0};

    head = malloc(sizeof(header_t));
    info->size = 0;
    head->magic = COREWAR_EXEC_MAGIC;
    swap_int(&(head->magic));
    if (parsing(argc, argv) == 0) {
        write(1, "Usage: ./asm file_name[.s] ....\n", 32);
        return (0);
    }
    info->file = read_map(argv[1]);
    if (info->file == NULL)
        return (84);
    create_file_cor(argv[1], info);
    the_parsing(info, head);
    return (1);
}

int main (int argc, char **argv)
{
    asm_start(argc, argv);
    return (0);
}