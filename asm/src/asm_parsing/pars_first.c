/*
** EPITECH PROJECT, 2018
** duo_stumper_4_2018
** File description:
** main.c
*/

#include "../../include/op.h"
#include "../../include/my.h"
#include "lib.h"

pars_axo_t pars_tab[] =
    {
        {"rrr", 84},
        {"ddr", 164},
        {"iir", 244},
        {"idr", 180},
        {"dir", 228},
        {"drr", 148},
        {"rdr", 100},
        {"irr", 212},
        {"rir", 116},
    };

int check_d_all(char *str)
{
    int dir = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '%')
            if (str[i + 1] != ':')
                dir++;
    }
    return (dir);
}

int check_size(file_t *info, char *str, int j)
{
    int direct = 0;
    int i = 0;
    int label = 0;
    int registre = 0;
    int indirect = 0;

    for (; str[i] != ' '; i++);
    direct = check_d_all(str);
    registre = check_r_all(str, i);
    for (; str[i]; i++)
        if (str[i] == '%')
            if (str[i + 1] == ':')
                label++;
    if (registre + direct < op_tab[j].nbr_args)
        indirect = op_tab[j].nbr_args - (registre + direct);
    info->size += op_tab[j].nbr_args + 1 + (3 * direct) + (1 * indirect) + op_tab[j].args + label;
    return (0);
}

int pars_aox(file_t *info, char *str)
{
    int i = 0;
    int dir = check_dir(str, i);
    char tkt[3];

    tkt[0] = dir == 0 ? 'r' : (dir == 1) ? 'd' : 'i';
    for (; str[i] != ',' && str[i]; i++);
    i++;
    dir = check_dir(str, i);
    tkt[1] = dir == 0 ? 'r' : (dir == 1) ? 'd' : 'i';
    tkt[2] = 'r';
    for (int i = 0; pars_tab[i].str; i++)
        if (my_strcmp(pars_tab[i].str, tkt) == 1)
            write(info->fd, &(pars_tab[i].nbr_diff), 1);
    return (0);
}

int the_parsing(file_t *info, header_t *head)
{
    add_head(info, head);
    add_size(info);
    swap_int(&info->size);
    head->prog_size = info->size;
    write(info->fd, head, sizeof(header_t));
    write_all(info);
    return (0);
}