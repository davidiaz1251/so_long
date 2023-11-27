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

BSOURCE =	bonus/so_long_bonus.c		\
			bonus/init_bonus.c		\
			bonus/screen_bonus.c		\
			bonus/print_map_bonus.c	\
			bonus/movements_bonus.c	\
			bonus/free_bonus.c		\
			bonus/collected_bonus.c	\
			bonus/open_image_bonus.c	\
			bonus/exit_bonus.c

OBJ = $(SOURCE:.c=.o)
BOBJ = $(BSOURCE:.c=.o)
LIBFT = libft.a

all : $(NAME)
	@echo "\x1b[32m Compilacion OK"

$(NAME): $(OBJ) $(LIBFT) mlx/libmlx.a
	@$(CC) $(OBJ) -Lmlx -lmlx -LLibft -lft -framework OpenGL -framework AppKit -o $(NAME)

mlx/libmlx.a:
	make -C mlx/

$(LIBFT) : 
	@make -C ./Libft/

bonus: $(BOBJ) $(LIBFT) mlx/libmlx.a
	@$(CC) $(BOBJ) -Lmlx -lmlx -LLibft -lft -framework OpenGL -framework AppKit -o so_long_bonus

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
run:
	./$(NAME) maps/map.ber

runb:
	./bonus/so_long_bonus maps/map_bonus.ber

clean:
	@rm -f $(OBJ)
	@rm -f $(BOBJ)
	@make -C mlx/ clean
	@make -C Libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C Libft/ fclean

re: fclean all

.PHONY: fclean re clean run bonus 