NAME = so_long
SOURCE =	so_long.c		\
			init.c			\
			screen.c		\
			print_map.c		\
			movements.c		\
			free.c			\
			collected.c		\
			open_image.c	\
			exit.c

OBJ = $(SOURCE:.c=.o)
LIBFT = libft.a

all : $(NAME)
	@echo "\x1b[32m Compilacion OK"

$(NAME): $(OBJ) $(LIBFT) mlx/libmlx.a
	@$(CC) $(OBJ) -Lmlx -lmlx -LLibft -lft -framework OpenGL -framework AppKit -o $(NAME)

mlx/libmlx.a:
	make -C mlx/

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(LIBFT) : 
	@make -C ./Libft/

run:
	./$(NAME) maps/map.ber

clean:
	rm -f $(OBJ)
	make -C mlx/ clean
	make -C Libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C Libft/ fclean

re: fclean all

.PHONY: fclean re clean r 