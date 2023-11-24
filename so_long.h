/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:27:44 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/24 12:37:29 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define ROJO_T			"\x1b[31m"
#define RESET_COLOR		"\x1b[0m"
#define BUFFER_SIZE		1000
#define WIDTH			128
#define HEIGHT			128
#define EXTENSION		".ber"
#define TOP				13
#define BOTTOM			1
#define LEFT			0
#define RIGHT			2
#define MURO			"./sprites/muro.xpm"
#define CESPED			"./sprites/cesped.xpm"
#define PER_B			"./sprites/MarioB.xpm"
#define PER_B1			"./sprites/MarioB1.xpm"
#define PER_L			"./sprites/MarioL.xpm"
#define PER_L1			"./sprites/MarioL1.xpm"
#define PER_R			"./sprites/MarioR.xpm"
#define PER_R1			"./sprites/MarioR1.xpm"
#define PER_T			"./sprites/MarioT.xpm"
#define PER_T1			"./sprites/MarioT1.xpm"
#define PUERTA			"./sprites/puerta.xpm"
#define COIN			"./sprites/coin.xpm"

typedef struct s_game t_game;
typedef struct s_vars t_vars;

typedef struct s_game
{
	int coins;
	int collected;
	int	steps;
	int exits;
	int person;
	int img_width;
	int img_height;
	int frame;
	int priority;
	char *map;
	char *img_p;
	void *img;
	char **map_array;
	char **map_copy;
	size_t map_x_len;
	size_t map_y_len;
	size_t p_y;
	size_t p_x;
	size_t x;
	size_t y;
	t_vars *vars;
	
} t_game;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_game	*game;
}				t_vars;
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void init(t_game *game, char *name_map);
void	coor_person(t_game *game, size_t y, size_t x);
void	ft_error(char *error);
void	get_screen(t_vars *vars, t_game *game);
int	print_map(t_game *game);
int	animation(t_game *game);
void move_top(t_vars *vars);
void move_left(t_vars *vars);
void move_right(t_vars *vars);
void move_bottom(t_vars *vars);
int	collected(t_vars *vars);