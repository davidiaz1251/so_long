/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:31:46 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/27 13:14:33 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_screen(t_vars *vars, t_game *game)
{
	int	x;
	int	y;

	x = game->map_x_len * WIDTH;
	y = game->map_y_len * HEIGHT;
	vars->game = game;
	game->vars = vars;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, x, y, "so_long");
}
