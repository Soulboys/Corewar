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

void disp_second_part_help(void)
{
    write(1, "-a load_address sets the next program’s loading address.", 58);
    write(1, "  When no address is\n", 21);
    write(1, "                        ", 24);
    write(1, "specified, optimize the", 23);
    write(1, " addresses so that the processes are as far\n", 44);
    write(1, "                        ", 24);
    write(1, "away from each other as possible. ", 34);
    write(1, " The addresses are MEM_SIZE modulo.\n", 36);
}

void disp_help(void)
{
    write(1, "USAGE\n        ", 15);
    write(1, "./corewar [-dump nbr_cycle] [[-n prog_number] ", 48);
    write(1, "[-a load_address] prog_name] ...\n\n", 34);
    write(1, "DESCRIPTION\n        ", 20);
    write(1, "-dump nbr_cycle dumps the memory after", 38);
    write(1, " the nbr_cycle execution (if the round isn’t\n", 47);
    write(1, "                        already", 31);
    write(1, " over) with the following format:  32 bytes/line in\n", 52);
    write(1, "                        ", 24);
    write(1, "hexadecimal (A0BCDEFE1DD3...)\n", 31);
    write(1, "        ", 8);
    write(1, "-n prog_number  sets the next program’s number.  ", 51);
    write(1, "By default, the first free number\n", 34);
    write(1, "                        ", 24);
    write(1, "in the parameter order\n", 23);
    write(1, "        ", 8);
    disp_second_part_help();
}

int my_str_cmp(char *str1, char *str2)
{
    int size1 = 0;
    int size2 = 0;

    for (; str1[size1] ; size1++);
    for (; str2[size2] ; size2++);
    if (size1 != size2) {
        return (0);
    }
    for (int i = 0; str1[i] ; i++)
        if (str1[i] != str2[i])
            return (0);
    return (1);
}

int error_handler_vm(int argc, char **argv)
{
    if (argc < 2) {
        write(1, "error\n", 6);
        return (84);
    } else if (my_str_cmp(argv[1], "-h") == 1 && argc == 2) {
        disp_help();
        return (84);
    }
    return (0);
}

int check_end(char *str)
{
    int i = 0;

    if (str == NULL) {
        return (0);
    } else if (str[0] == '-' && str[1] == 'd') {
        return (2);
    }
    if (str[0] == '-' && str[1] == 'a') {
        return (3);
    } else if (str[0] == '-' && str[1] == 'n') {
        return (4);
    }
    for (; str[i] ; i++);
    if (i < 5)
        return (0);
    if (str[i - 1] != 'r' && str[i - 2] != 'o' &&
    str[i - 3] != 'c' && str[i - 4] != '.')
        return (0);
    return (1);
}