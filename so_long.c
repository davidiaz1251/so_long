/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:27:53 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/27 11:58:18 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		free_matrix(vars->game->map_array);
		ft_close(vars);
	}
	else if (keycode == TOP)
		move_top(vars);
	else if (keycode == BOTTOM)
		move_bottom(vars);
	else if (keycode == LEFT)
		move_left(vars);
	else if (keycode == RIGHT)
		move_right(vars);
	return (0);
}

int	animation(t_game *game)
{
	if (game->priority == 1)
	{
		if (game->frame == 10)
		{
			game->img_p = PER_B;
			game->frame = 0;
			game->priority = 0;
		}
		else
			game->frame++;
	}
	return (0);
}

void	coor_person(t_game *game, size_t y, size_t x)
{
	game->person++;
	game->p_y = y;
	game->p_x = x;
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	t_game	game;

	if (argc == 2)
	{
		init(&game, argv[1]);
		get_screen(&vars, &game);
		mlx_key_hook(vars.win, key, &vars);
		mlx_hook(vars.win, ON_DESTROY, 0, ft_close, &vars);
		mlx_loop_hook(vars.mlx, print_map, &game);
		mlx_loop(vars.mlx);
	}
	else
		ft_error("./so_long maps/<map>.ber");
	exit (1);
}
