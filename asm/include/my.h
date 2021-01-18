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
    #include "op.h"
    #include <fcntl.h>
    #include <unistd.h>

    typedef char bytesint[4];
    typedef char bytes_two_int[2];

    typedef struct inst_s {
        char *type;
        void (*function)();
    } inst_t;

    typedef struct pars_axo {
        char *str;
        int nbr_diff;
    } pars_axo_t;

    typedef struct file_s {
        char *name;
        char **file;
        int status;
        int size;
        int fd;
    } file_t;

    void add_head(file_t *info, header_t *head);
    void add_size(file_t *info);
    void write_all(file_t *info);
    int search_comment(char *str, header_t *head);
    int search_name(char *str, header_t *head);
    int check_reg(char *str, int i);
    int check_dir(char *str, int i);
    int check_r_all(char *str, int i);
    int pars_aox(file_t *info, char *str);
    int my_strcmp2(char *s1, char *s2);
    int the_write(file_t *info, char *str, int i);
    char *rac_str(char *src);
    char **str_to_array(char *, char);
    char *clean_str(char *src);
    char **read_map(char *);
    int my_strcmp2(char *s1, char *s2);
    void fct_or(file_t *info, char *str, int j);
    void fct_xor(file_t *info, char *str, int j);
    void fct_and(file_t *info, char *str, int j);
    void fct_sub(file_t *info, char *str, int j);
    void fct_add(file_t *info, char *str, int j);
    void swap_short(void *val);
    int parsing(int argc, char **);
    void fct_ld(file_t *info, char *str, int j);
    void fct_live(file_t *info, char *str, int j);
    void swap_int(void *val);
    int check_err(char **);
    void fct_st(file_t *info, char *str, int j);
    void create_file_cor(char *, file_t *);
    int the_parsing(file_t *info, header_t *head);
    int reg_int(file_t *info, int j);


#endif /* MY_H_ */
