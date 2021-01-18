/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <SFML/Graphics.h>
#include <stdarg.h>

#ifndef MY_H
#define MY_H
#define READ_SIZE (4096)

typedef struct print_s {
    char type;
    int (*function)();
}print_t;

/**number.c**/
int my_getnbr(char const *);
int my_ngetnbr(char const *str, int n);
char *int_to_str(int);
int get_int_size(int);

/**put.c**/
int my_putchar(char);
void my_putstr(char const *);
void my_put_nbr(long long);
char *my_strlowcase(char *);

/**str_to_array.c**/
char **str_to_array(char *, char);

/**sttr_utils.c**/
int my_strlen(char const *);
char *my_revstr(char *);
int my_search_word(char *str, char *word);
int my_strcmp(char *s1, char *s2);
char *my_strcat(char *to_join, char *str);
char *my_strcpy(char *dest, char const *src);

/**get_next_line.c**/
char *gnl(int);

/**math.c**/
int my_compute_power_rec(int, int);
int my_compute_square_root(int);

/**my_printf.c**/
int my_printf(char *, ...);
int count_putchar(va_list to_print);
int count_putstr(va_list to_print);
int count_putnbr(va_list to_print);

int my_printf_error(char *, ...);
int count_putchar_err(va_list to_print);
int count_putstr_err(va_list to_print);
int count_putnbr_err(va_list to_print);

/**str_use.c**/
void swap(char **, char **);

/***cfsml_utils.c***/
sfSprite *create_sprite(sfTexture *texture, float);
sfText *create_text(char *string, int size, sfFont *font);
void draw_sprite(sfSprite *sprite, int x, int y, sfRenderWindow *window);
void draw_text(sfText *text, int x, int y, sfRenderWindow *window);
sfIntRect create_rec(int top, int left, int width, int height);

#endif
