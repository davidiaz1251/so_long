/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:33:27 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/27 11:50:36 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_map(t_game *game)
{
	game->y = -1;
	game->x = -1;
	mlx_clear_window(game->vars->mlx, game->vars->win);
	while (game->map_array[++game->y])
	{
		while (game->map_array[game->y][++game->x])
		{
			if (game->map_array[game->y][game->x] == '1')
				game->img = image(game, '1');
			else if (game->map_array[game->y][game->x] == 'P')
				game->img = image(game, 'P');
			else if (game->map_array[game->y][game->x] == 'E')
				game->img = image(game, 'E');
			else if (game->map_array[game->y][game->x] == 'C')
				game->img = image(game, 'C');
			else
				game->img = image(game, '0');
			mlx_put_image_to_window(game->vars->mlx, game->vars->win, \
			game->img, game->x * WIDTH, game->y * HEIGHT);
		}
		game->x = -1;
	}
	print_count(game);
	return (0);
}
