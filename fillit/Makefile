NAME=fillit
SRC=checks.c display.c fillit.c init.c split.c ft_blocks.c
HEAD=fillit.h
LIB=libft/libft.a

all : $(NAME)

$(NAME):
	make -C libft
	gcc -I$(HEAD) -Wall -Werror -Wextra -c $(SRC)
	gcc -Wall -Werror -Wextra $(LIB) checks.o display.o fillit.o init.o split.o ft_blocks.o -o $(NAME)
clean :
	/bin/rm -rf checks.o display.o fillit.o init.o split.o ft_blocks.o
	make -C libft clean
fclean : clean
	/bin/rm -rf $(NAME)
	make -C libft fclean
re : fclean all
