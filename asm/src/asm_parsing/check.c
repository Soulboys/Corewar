/*
** EPITECH PROJECT, 2018
** duo_stumper_4_2018
** File description:
** main.c
*/

#include "../../include/op.h"
#include "../../include/my.h"
#include "lib.h"

int search_comment(char *str, header_t *head)
{
    int i = 0;

    for(; str[i] != '"'; i++);
    i++;
    for (int j = 0; str[i + 1]; i++, j++)
        head->comment[j] = str[i];
    return (0);
}

int search_name(char *str, header_t *head)
{
    int i = 0;

    for(; str[i] != '"'; i++);
    i++;
    for (int j = 0; str[i + 1]; i++, j++)
        head->prog_name[j] = str[i];
   return (0);
}

int check_reg(char *str, int i)
{
    int reg = 0;

    i++;
    if (str == NULL)
        return (0);
    for (; str[i] && str[i] != ','; i++) {
        if (str[i] == 'r') {
            reg++;
        }
    }
    return (reg);
}

int check_dir(char *str, int i)
{
    int dir = 0;
    int reg = check_reg(str, i);

    for (; str[i] != ',' && str[i]; i++) {
        if (str[i] == '%')
            dir++;
    }
    if (dir == 0 && reg == 0)
        return (-1);
    else if (reg == 1)
        return (0);
    return (dir);
}

int check_r_all(char *str, int i)
{
    int reg = 0;

    for (; str[i]; i++) {
        if (str[i] == 'r')
            reg++;
    }
    return (reg);
}