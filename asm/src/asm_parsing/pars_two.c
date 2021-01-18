/*
** EPITECH PROJECT, 2018
** duo_stumper_4_2018
** File description:
** main.c
*/

#include "../../include/op.h"
#include "../../include/my.h"
#include "lib.h"

int the_write(file_t *info, char *str, int i)
{
    int dir = check_dir(str, i);
    int wr = 0;

    wr = my_ngetnbr(str, i);
    if (dir == 1) {
        swap_int(&wr);
        write(info->fd, &wr, 4);
    } else if (dir == -1) {
        swap_short(&wr);
        write(1, &wr, 2);
        write(info->fd, &wr, 2);
    } else if (dir == 0)
        write(info->fd, &wr, 1);
    for (; str[i] != ',' && str[i]; i++);
    return (i + 1);
}

void fct_xor(file_t *info, char *str, int j)
{
    int i = 0;

    write(info->fd, &(op_tab[j].code), 1);
    pars_aox(info, str);
    i = the_write(info, str, i);
    i = the_write(info, str, i);
    i = the_write(info, str, i);
}

void fct_or(file_t *info, char *str, int j)
{
    int i = 0;

    write(info->fd, &(op_tab[j].code), 1);
    pars_aox(info, str);
    i = the_write(info, str, i);
    i = the_write(info, str, i);
    i = the_write(info, str, i);
}

void fct_and(file_t *info, char *str, int j)
{
    int i = 0;

    write(info->fd, &(op_tab[j].code), 1);
    pars_aox(info, str);
    i = the_write(info, str, i);
    i = the_write(info, str, i);
    i = the_write(info, str, i);
}
