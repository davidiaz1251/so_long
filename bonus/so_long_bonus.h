/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:27:44 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/27 13:31:42 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define ROJO_T			"\x1b[31m"
# define RESET_COLOR		"\x1b[0m"
# define BUFFER_SIZE		1000
# define WIDTH			128
# define HEIGHT			128
# define EXTENSION		".ber"
# define TOP				13
# define BOTTOM			1
# define LEFT			0
# define RIGHT			2
# define ON_DESTROY		17
# define MURO			"./textures/muro.xpm"
# define CESPED			"./textures/cesped.xpm"
# define ENEMY			"./textures/enemy.xpm"
# define PER_B			"./textures/MarioB.xpm"
# define PER_B1			"./textures/MarioB1.xpm"
# define PER_L			"./textures/MarioL.xpm"
# define PER_L1			"./textures/MarioL1.xpm"
# define PER_R			"./textures/MarioR.xpm"
# define PER_R1			"./textures/MarioR1.xpm"
# define PER_T			"./textures/MarioT.xpm"
# define PER_T1			"./textures/MarioT1.xpm"
# define PUERTA			"./textures/puerta.xpm"
# define COIN			"./textures/coin.xpm"

typedef struct s_game	t_game;
typedef struct s_vars	t_vars;

typedef struct s_game
{
	int		coins;
	int		colle;
	int		steps;
	int		exits;
	int		person;
	int		enemy;
	int		img_width;
	int		img_height;
	int		frame;
	int		priority;
	char	*map;
	char	*img_p;
	char	**map_array;
	char	**map_copy;
	void	*img;
	size_t	map_x_len;
	size_t	map_y_len;
	size_t	p_y;
	size_t	p_x;
	size_t	x;
	size_t	y;
	t_vars	*vars;
}	t_game;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_game	*game;
}				t_vars;

void	init(t_game *game, char *name_map);
void	coor_person(t_game *game, size_t y, size_t x);
void	ft_error(char *error);
void	get_screen(t_vars *vars, t_game *game);
void	move_top(t_vars *vars);
void	move_left(t_vars *vars);
void	move_right(t_vars *vars);
void	move_bottom(t_vars *vars);
void	print_count(t_game *game);
void	check_object(t_game *game);
void	*image(t_game *game, char c);
void	ft_error(char *error);
int		print_map(t_game *game);
int		animation(t_game *game);
int		collected(t_vars *vars);
int		ft_close(t_vars *vars);
int		ft_close(t_vars *vars);
char	**free_matrix(char **memory);
#endif