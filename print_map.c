/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:33:27 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/24 12:52:34 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_map(t_game *game)
{
	game->y = 0;
	game->x = 0;
	animation(game);	
	mlx_clear_window(game->vars->mlx,game->vars->win);
	while (game->map_array[game->y])
	{
		while (game->map_array[game->y][game->x])
		{
			if (game->map_array[game->y][game->x] == '1')
				game->img = mlx_xpm_file_to_image(game->vars->mlx, MURO, &game->img_height, &game->img_width);
			else if(game->map_array[game->y][game->x] == 'P')
				game->img = mlx_xpm_file_to_image(game->vars->mlx, game->img_p , &game->img_height, &game->img_width);
			else if(game->map_array[game->y][game->x] == 'E')
				game->img = mlx_xpm_file_to_image(game->vars->mlx, PUERTA, &game->img_height, &game->img_width);
			else if(game->map_array[game->y][game->x] == 'C')
				game->img = mlx_xpm_file_to_image(game->vars->mlx, COIN, &game->img_height, &game->img_width);
			else
				game->img = mlx_xpm_file_to_image(game->vars->mlx, CESPED, &game->img_height, &game->img_width);
			mlx_put_image_to_window(game->vars->mlx, game->vars->win, game->img, game->x * WIDTH, game->y * HEIGHT);
			game->x++;
		}
		game->x = 0;
		game->y++;
	}
	return (0);
}
