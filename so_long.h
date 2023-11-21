/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:27:44 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/21 11:40:03 by ldiaz-ra         ###   ########.fr       */
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
#define EXTENSION		".ber"

typedef struct s_game
{
	int coins;
	int exits;
	int person;
	char *map;
	char **map_array;
	char **map_copy;
	size_t map_x_len;
	size_t map_y_len;
	size_t p_y;
	size_t p_x;
	size_t x;
	size_t y;
	
} t_game;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
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