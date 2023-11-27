/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:18:16 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/27 14:21:50 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_muro(t_game *game)
{
	game->y = -1;
	game->x = -1;
	while (game->map_array[++game->y])
	{
		while (game->map_array[game->y][++game->x])
		{
			if ((game->y == 0 || game->y == game->map_y_len - 1) \
			&& (game->map_array[game->y][game->x] != '1'))
				ft_error("Muros malos");
			else if ((game->map_array[game->y][0] != '1') \
			|| (game->map_array[game->y][game->map_x_len - 1] != '1'))
				ft_error("Muros malos");
			else if (game->map_array[game->y][game->x] == 'C')
				game->coins++;
			else if (game->map_array[game->y][game->x] == 'E')
				game->exits++;
			else if (game->map_array[game->y][game->x] == 'M')
				game->enemy++;
			else if (game->map_array[game->y][game->x] == 'P')
				coor_person(game, game->y, game->x);
		}
		game->x = -1;
	}
	if ((game->exits != 1) || (game->person != 1) || (game->coins < 1))
		ft_error("Mapa Malo!!");
}

static void	read_map(char *map, t_game *game)
{
	int		fd;
	int		i;
	char	*ext;

	fd = open(map, O_RDWR);
	if (fd < 0)
		ft_error("Problemas al abrir el archivo");
	i = 0;
	ext = ft_strrchr(map, '.');
	while (ext[i])
	{
		if (ext[i] != EXTENSION[i])
			ft_error("Extension de archivo invalida");
		i++;
	}
	game->map = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	read(fd, game->map, BUFFER_SIZE);
	close(fd);
}

static void	check_map(t_game *game)
{
	game->map_y_len = 0;
	game->map_array = ft_split(game->map, '\n');
	if (!game->map_array)
		free_matrix(game->map_array);
	game->map_copy = ft_split(game->map, '\n');
	if (!game->map_copy)
		free_matrix(game->map_copy);
	game->map_x_len = ft_strlen(game->map_array[0]);
	while (game->map_array[game->map_y_len])
	{
		if (game->map_x_len != ft_strlen(game->map_array[game->map_y_len]))
			ft_error("El mapa debe ser rectangular!!");
		game->map_y_len++;
	}
	check_muro(game);
}

static int	check_rut(size_t y, size_t x, t_game *game)
{
	if (game->map_copy[y][x] == 'E' || game->map_copy[y][x] == 'M')
	{
		game->map_copy[y][x] = '.';
		return (0);
	}
	game->map_copy[y][x] = '.';
	if (game->map_copy[y - 1][x] != '1' && game->map_copy[y - 1][x] != '.')
		check_rut(y - 1, x, game);
	if (game->map_copy[y + 1][x] != '1' && game->map_copy[y + 1][x] != '.')
		check_rut(y + 1, x, game);
	if (game->map_copy[y][x + 1] != '1' && game->map_copy[y][x + 1] != '.')
		check_rut(y, x + 1, game);
	if (game->map_copy[y][x - 1] != '1' && game->map_copy[y][x - 1] != '.')
		check_rut(y, x - 1, game);
	return (0);
}

void	init(t_game *game, char *name_map)
{
	game->coins = 0;
	game->colle = 0;
	game->steps = 0;
	game->exits = 0;
	game->person = 0;
	game->enemy = 0;
	game->img_p = PER_B;
	game->frame = 0;
	game->priority = 0;
	read_map(name_map, game);
	check_map(game);
	check_rut(game->p_y, game->p_x, game);
	check_object(game);
	free(game->map);
	free_matrix(game->map_copy);
}
