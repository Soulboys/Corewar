##
## EPITECH PROJECT, 2018
## Corewar
## File description:
## makefile for vm part of the corewar
##

SRC	=	main.c								\
		loop.c								\
		open_file.c							\
		trad_magic.c						\
		trad_action.c						\
		error_handler_vm.c					\
		../my_printf/my_nbrlen.c			\
		../my_printf/my_printf.c			\
		../my_printf/my_printf2.c			\
		../my_printf/my_printf3.c			\
		../my_printf/my_putchar.c			\
		../my_printf/my_putnbr_base_uns.c	\
		../my_printf/my_putnbr_uns.c		\
		../my_printf/my_putnbr.c			\
		../my_printf/my_putstr.c			\
		../my_printf/my_revstr.c			\
		../my_printf/my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

CFLAGS += -g -Wall -Wextra
LDFLAGS+= -L../lib -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	$(MAKE) -C ../lib
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
