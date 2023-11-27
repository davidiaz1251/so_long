/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:23:20 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/27 11:43:04 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*image(t_game *game, char c)
{
	void	*img;

	if (c == '1')
		img = mlx_xpm_file_to_image(game->vars->mlx, \
		MURO, &game->img_height, &game->img_width);
	else if (c == 'P')
		img = mlx_xpm_file_to_image(game->vars->mlx, \
		game->img_p, &game->img_height, &game->img_width);
	else if (c == 'E')
		img = mlx_xpm_file_to_image(game->vars->mlx, \
		PUERTA, &game->img_height, &game->img_width);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(game->vars->mlx, \
		COIN, &game->img_height, &game->img_width);
	else
		img = mlx_xpm_file_to_image(game->vars->mlx, \
		CESPED, &game->img_height, &game->img_width);
	if (!img)
		ft_error("Sprites Mal");
	return (img);
}
