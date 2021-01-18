/*
** EPITECH PROJECT, 2018
** duo_stumper_4_2018
** File description:
** main.c
*/

#include "../../include/op.h"
#include "../../include/my.h"
#include "lib.h"

void add_head(file_t *info, header_t *head)
{
    for (int i = 0; info->file[i]; i++) {
        if ((my_strcmp(info->file[i], ".name") == 1))
            search_name(info->file[i], head);
        else if ((my_strcmp(info->file[i], ".comment") == 1))
            search_comment(info->file[i], head);
    }
}

void add_size(file_t *info)
{
    char *str_clean = NULL;

    for (int i = 2; info->file[i]; i++) {
        str_clean = clean_str(info->file[i]);
        for (int j = 0 ;op_tab[j].mnemonique; j++) {
            if (my_search_word(str_clean, op_tab[j].mnemonique) == 1) {
                check_size(info, info->file[i], j);
            }
        }
    }
}

void write_all(file_t *info)
{
    char *str = NULL;
    char *str_clean = NULL;

    for (int i = 2; info->file[i]; i++) {
        str_clean = clean_str(info->file[i]);
        for (int j = 0 ;op_tab[j].mnemonique; j++) {
            str = rac_str(info->file[i]);
            if (my_search_word(str_clean, op_tab[j].mnemonique) == 1) {
                op_tab[j].fct(info, str, j);
                free(str);
            }
        }
    }
}
