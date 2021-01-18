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

link_t *add_second_part(link_t *new)
{
    new->magic_number = trad_magic(new);
    new->name = trad_name(new);
    new->comment = trad_comment(new);
    new->action = trad_action(new);
    new->status = CYCLE_TO_DIE;
    new->live = 0;
    new->dump = 0;
    return (new);
}

link_t *add_to_list(char *file, link_t *list, int *integer, int place)
{
    link_t *new = malloc(sizeof(link_t));

    new->file_core = open_file_vm(file, new);
    new->number = integer[1];
    if (integer[0] > 0 && integer[0] < 5)
        new->number = integer[0];
    new->back = NULL;
    new->next = NULL;
    new->place = 0;
    if (place > 0)
        new->place = place;
    new = add_second_part(new);
    if (list != NULL) {
        new->next = list;
        list->back = new;
    }
    return (new);
}

link_t *delete_link_vm(link_t *link)
{
    link_t *new = malloc(sizeof(link_t));

    write(1, "invalid magic number\n", 21);
    if (link->next) {
        new = link->next;
        new->back = NULL;
    }
    if (link->next == NULL && link->back == NULL) {
        new = NULL;
    }
    return (new);
}

link_t *do_action_to_list(link_t *list, int i, char **argv, int *dump)
{
    static int integer[2] = {0, 1};
    static int place = 0;

    if (check_end(argv[i]) == 4 && argv[i + 1] != NULL)
        integer[0] = my_getnbr(argv[i + 1]);
    if (check_end(argv[i]) == 2 && argv[i + 1] != NULL)
        *dump = my_getnbr(argv[i + 1]);
    if (check_end(argv[i]) == 3 && argv[i + 1] != NULL)
        place = my_getnbr(argv[i + 1]);
    if (check_end(argv[i]) == 1) {
        list = add_to_list(argv[i], list, integer, place);
        place = 0;
        integer[0] = 0;
        integer[1]++;
        if (list == NULL)
            return (NULL);
        if (check_the_magic(list) == 1)
            list = delete_link_vm(list);
    }
    return (list);
}

int main (int argc, char **argv)
{
    link_t *list = NULL;
    int dump = 0;

    if (error_handler_vm(argc, argv) == 84)
        return (84);
    for (int i = 1 ; i < argc ; i++) {
        list = do_action_to_list(list, i, argv, &dump);
    }
    if (list != NULL)
        loop(list, dump);
    return (0);
}
