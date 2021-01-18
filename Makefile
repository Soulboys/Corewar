##
## EPITECH PROJECT, 2018
## makefile
## File description:
## this file is used for compliation of src and lib
##

all:
	@make -C ./asm/
	@make -C ./corewar/

clean:
	@make -C ./asm/ clean
	@make -C ./corewar/ clean
	@rm -f $(OBJ)

fclean:
	@make -C ./corewar/ fclean
	@make -C ./asm/ fclean
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@rm -f vgcore.*

re:		fclean all

.PHONY: 	all clean fclean re
