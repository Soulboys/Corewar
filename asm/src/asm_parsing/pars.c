/*
** EPITECH PROJECT, 2018
** duo_stumper_4_2018
** File description:
** main.c
*/

#include "../../include/op.h"
#include "../../include/my.h"
#include "lib.h"

void fct_sub(file_t *info, char *str, int j)
{
    int i = 0;
    int k = 84;

    write(info->fd, &(op_tab[j].code), 1);
    write(info->fd, &k, 1);
    i = the_write(info, str, i);
    i = the_write(info, str, i);
    i = the_write(info, str, i);
}

void fct_add(file_t *info, char *str, int j)
{
    int i = 0;
    int k = 84;

    write(info->fd, &(op_tab[j].code), 1);
    write(info->fd, &k, 1);
    i = the_write(info, str, i);
    i = the_write(info, str, i);
    i = the_write(info, str, i);
}

void fct_st(file_t *info, char *str, int j)
{
    int i = 0;
    int check = check_r_all(str, 0);
    int k = check == 2 ? 50 : 112;

    write(info->fd, &(op_tab[j].code), 1);
    write(info->fd, &k, 1);
    i = the_write(info, str, i);
    i = the_write(info, str, i);
}

void fct_ld(file_t *info, char *str, int j)
{
    int i = 0;
    int k = check_d_all(str) > 0 ? 144 : 208;

    write(info->fd, &(op_tab[j].code), 1);
    write(info->fd, &k, 1);
    i = the_write(info, str, i);
    i = the_write(info, str, i);
}


void fct_live(file_t *info, char *str, int j)
{
    int test = my_getnbr(str);

    swap_int(&test);
    write(info->fd, &(op_tab[j].code), 1);
    write(info->fd, &test, 4);
}