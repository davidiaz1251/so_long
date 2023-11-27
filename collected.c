/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collected.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:23:35 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/27 11:17:22 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collected(t_vars *vars)
{
	return (vars->game->coins == vars->game->colle);
}

void	check_object(t_game *game)
{
	game->y = 0;
	game->x = 0;
	while (game->map_copy[game->y])
	{
		while (game->map_copy[game->y][game->x])
		{
			if (game->map_copy[game->y][game->x] == 'C')
				ft_error("No puedes recoger todas las monedas");
			else if (game->map_copy[game->y][game->x] == 'E')
				ft_error("No puedes llegar a la salida");
			game->x++;
		}
		game->x = 0;
		game->y++;
	}
}

void	print_count(t_game *game)
{
	char	*steps;
	char	*coins;
	char	*colle;

	steps = ft_itoa(game->steps);
	coins = ft_itoa(game->coins);
	colle = ft_itoa(game->colle);
	mlx_string_put(game->vars->mlx, game->vars->win, 50, 50, 0xFFFFFF, "Steps");
	mlx_string_put(game->vars->mlx, game->vars->win, 100, 50, 0xFFFFFF, steps);
	mlx_string_put(game->vars->mlx, game->vars->win, 50, 70, 0xFFFFFF, "Coins");
	mlx_string_put(game->vars->mlx, game->vars->win, 100, 70, 0xFFFFFF, colle);
	mlx_string_put(game->vars->mlx, game->vars->win, 110, 70, 0xFFFFFF, "/");
	mlx_string_put(game->vars->mlx, game->vars->win, 120, 70, 0xFFFFFF, coins);
	free(steps);
	free(coins);
	free(colle);
}
