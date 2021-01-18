/*
** EPITECH PROJECT, 2018
** PSU_tetris_2018
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include <unistd.h>

    typedef struct inst_s {
        char *type;
        int (*function)();
    }inst_t;

    typedef struct file_s {
        char *name;
        char **file;
        int fd;
    } file_t;

    int parsing(int argc, char **);
    char **open_file(char *);
    void fct_live(file_t *info);
    int check_err(char **);
    void create_file_cor(char *, file_t *);
    int the_parsing(file_t *info);
    int reg_int(file_t *info, int j);
    
#endif /* MY_H_ */
