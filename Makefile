NAME = so_long
SOURCE = so_long.c 
OBJ = $(SOURCE:.c=.o)
LIBFT = libft.a

all : $(NAME)
	@echo "\x1b[32m Compilacion OK"

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(OBJ) -Lmlx -lmlx -LLibft -lft -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(LIBFT) : 
	@make -C ./Libft/
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all