NAME	= asm

CC	= gcc

RM	= rm -rf

REDDARK	=	\033[31;2m

RED	=	\033[31;1m

GREEN	=	\033[32;1m

YEL	=	\033[33;1m

BLUE	=	\033[34;1m

PINK	=	\033[35;1m

CYAN	=	\033[36;1m

RES	= \033[0m

SRCS	=	src/main.c	\
			src/asm_parsing/check.c	\
			src/asm_parsing/pars.c	\
			src/asm_parsing/pars_two.c	\
			src/asm_parsing/pars_three.c	\
			src/pars_file/parsing.c	\
			src/op.c	\
			src/open.c	\
			src/asm_parsing/pars_first.c	\
			src/asm_parsing/fct_utils.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -L./lib -lmy -g -lm

CSFMLFLAGS  =	-lcsfml-graphics -lcsfml-audio
CSFMLFLAGS += -lcsfml-window -lcsfml-system

all: start $(NAME)

$(NAME): $(OBJS)
	@echo -e " [$(RED)BINARY FILES$(RES)]        $(GREEN)DONE$(RES)"
	@make --no-print-directory -sC lib/
	@echo -e " [$(RED)COMPILE LIBRARY$(RES)]     $(GREEN)DONE$(RES)"
	@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(CFLAGS)
	@echo -e " [$(RED)COMPILE BINARY$(RES)]      $(GREEN)DONE$(RES)"
	@make --no-print-directory clean
	@echo -e " [$(RED)CLEAN$(RES)]               $(GREEN)DONE$(RES)"
	@echo -e "-----------------------------------------------------"
	@echo -e "                 $(YEL)$(NAME)$(RES)                 "


start:
	@echo -e " [$(RED)START$(RES)]"
	@echo -e "-----------------------------------------------------"

clean:
	@$(RM) $(OBJS)
	@$(RM) vgcore*

fclean: clean
	@$(RM) $(NAME)
	@echo -e " [$(RED)FCLEAN$(RES)]              $(GREEN)DONE$(RES)"

re: start fclean all

%.o:	%.c
	@gcc $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re
