/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:27:53 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/21 13:39:04 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *error)
{
	ft_putstr_fd(ROJO_T "Error\n\t" RESET_COLOR,1);
	ft_putstr_fd(error ,1);
	exit(1);
}
int ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
	return (0);
}
int	key(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_close(vars);
	return (0);
}
void	coor_person(t_game *game, size_t y, size_t x)
{
	game->person++;
	game->p_y = y;
	game->p_x = x;
}
void	read_map(char *map, t_game *game)
{
	int		fd;
	int		i;
	char	*ext;

	i = 0;
	ext = ft_strrchr(map, '.');
	while (ext[i])
	{
		if (ext[i] != EXTENSION[i])
			ft_error("Extension de archivo invalida");
		i++;
	}
	game->map = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	fd = open(map, O_RDWR);
	if (fd < 0)
		ft_error("Problemas al abrir el archivo");
	read(fd, game->map, BUFFER_SIZE);
	close(fd);
}
void	check_muro(t_game *game)
{
	game->y = 0;
	game->x = 0;
	while (game->map_array[game->y])
	{
		while (game->map_array[game->y][game->x])
		{
			if ((game->y == 0 || game->y == game->map_y_len - 1) && (game->map_array[game->y][game->x] != '1'))
				ft_error("Muros malos");
			else if (game->map_array[game->y][0] != '1' || game->map_array[game->y][game->map_x_len - 1] != '1')
				ft_error("Muros malos");
			else if(game->map_array[game->y][game->x] == 'C')
				game->coins++;
			else if(game->map_array[game->y][game->x] == 'E')
				game->exits++;
			else if(game->map_array[game->y][game->x] == 'P')
				coor_person(game, game->y, game->x);
			game->x++;
		}
		game->x = 0;
		game->y++;
	}
	if ((game->exits < 1 || game->exits > 1) || (game->person < 1 || game->person > 1))
		ft_error("Hay mas opciones de las permitidas!!");
}
int	check_rut(size_t y, size_t x, t_game *game)
{	
	if (game->map_copy[y][x] == 'E')
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
void	check_object(t_game *game)
{
	game->y = 0;
	game->x = 0;
	while (game->map_copy[game->y])
	{
		while (game->map_copy[game->y][game->x])
		{
			if(game->map_copy[game->y][game->x] == 'C')
				ft_error("No puedes recoger todas las monedas");
			else if(game->map_copy[game->y][game->x] == 'E')
				ft_error("No puedes llegar a la salida");
			game->x++;
		}
		game->x = 0;
		game->y++;
	}
}
void	check_map(t_game *game)
{
	game->coins = 0;
	game->exits = 0;
	game->person = 0;
	game->map_y_len = 0;
	game->map_array = ft_split(game->map,'\n');
	game->map_copy = ft_split(game->map,'\n');
	game->map_x_len = ft_strlen(game->map_array[0]);

	while (game->map_array[game->map_y_len])
	{
		if (game->map_x_len != ft_strlen(game->map_array[game->map_y_len]))
			ft_error("El mapa debe ser rectangular!!");
		game->map_y_len++;
	}
	check_muro(game);
}
int main(int argc, char *argv[])
{
	t_vars	vars;
	t_game	game;
	
	if (argc != 2)
	{
		//read_map(argv[1], &game);
		read_map("map1.ber", &game);
		check_map(&game);
		check_rut(game.p_y, game.p_x, &game);
		check_object(&game);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
		mlx_hook(vars.win, ON_KEYUP, 0, key, &vars);
		mlx_hook(vars.win, ON_DESTROY, 0, ft_close, &vars);
		// mlx_string_put(vars.mlx,vars.win,50,50,0x00FF00,"Hola Mundo");
		//mlx_loop_hook(vars.mlx, mouse, &vars);
		mlx_loop(vars.mlx);
	}
	else
		ft_error("./so_long <map>.ber");
	exit(1);
}
