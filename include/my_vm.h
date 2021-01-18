/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** corewar
*/

#ifndef VM_H_
#define VM_H_

#include "my.h"
#include "lib.h"
#include "op.h"

typedef struct champ_s {
    char *name;
    int number;
    int *magic;
    char *comment;
    char *instruction;
} champ_t;

typedef struct link_s {
    struct link_s *next;
    struct link_s *back;
    char *name;
    char *comment;
    int full_size;
    int number;
    int place;
    unsigned char **action;
    int *magic_number;
    unsigned char *file_core;
    int status;
    int live;
    int dump;
} link_t;

int error_handler_vm(int argc, char **argv);
void loop(link_t *list, int nb);
unsigned char **trad_action(link_t *new);
unsigned char *open_file_vm(char *file, link_t *new);
char *to_binary(int the);
char *my_revstr(char *str);
int my_strlen(char const *str);
int my_nbrlen(int nbr);
champ_t *init_champ(void);
int count_size(link_t *new);
char *trad_name(link_t *link);
int to_name(link_t *link);
int *trad_magic(link_t *link);
unsigned char *add_player_to_map(link_t *list, unsigned char *map);
int check_the_magic(link_t *link);
char *trad_comment(link_t *new);
int check_end(char *str);
int disp_player(link_t *list, int turn);

#endif
