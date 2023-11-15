/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:27:53 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/14 15:41:55 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
	return (0);
}
int	key(int keycode, t_vars *vars)
{
	printf("%i\n",keycode);
	printf("%p y %p\n",vars->mlx, vars->win);
	if (keycode == 53)
		close(vars);
	else if (keycode == 13)
		printf("\nArriba");
	return (0);
}
int main(int argc, char *argv[])
{
	t_vars	vars;
	int		file;
	char	memory[20];
	
	if (argc == 2)
	{
		file = open(argv[1], O_RDWR);
		printf("%s", argv[1]);
		read(file,memory,20);
		printf("%s",memory);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");

		mlx_hook(vars.win, ON_KEYUP, 0, key, &vars);
		mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);
		//mlx_string_put(vars.mlx,vars.win,50,50,0x00FF00,"Hola Mundo");
		//mlx_loop_hook(vars.mlx, mouse, &vars);
		mlx_loop(vars.mlx);
	}
}
