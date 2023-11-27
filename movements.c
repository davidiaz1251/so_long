/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:14:52 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/27 11:22:05 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_vars *vars)
{
	if (vars->game->map_array[vars->game->p_y][vars->game->p_x - 1] != '1')
	{
		if (vars->game->map_array[vars->game->p_y][vars->game->p_x - 1] == 'C')
			vars->game->colle++;
		if (vars->game->map_array[vars->game->p_y][vars->game->p_x - 1] == 'E')
		{
			if (collected(vars))
				ft_close(vars);
			else
				return ;
		}
		vars->game->map_array[vars->game->p_y][vars->game->p_x] = '0';
		vars->game->map_array[vars->game->p_y][vars->game->p_x - 1] = 'P';
		vars->game->p_x = vars->game->p_x - 1;
		vars->game->priority = 1;
		vars->game->img_p = PER_L;
		vars->game->steps++;
		ft_putnbr_fd(vars->game->steps, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_right(t_vars *vars)
{
	if (vars->game->map_array[vars->game->p_y][vars->game->p_x + 1] != '1')
	{
		if (vars->game->map_array[vars->game->p_y][vars->game->p_x + 1] == 'C')
			vars->game->colle++;
		if (vars->game->map_array[vars->game->p_y][vars->game->p_x + 1] == 'E')
		{
			if (collected(vars))
				ft_close(vars);
			else
				return ;
		}
		vars->game->map_array[vars->game->p_y][vars->game->p_x] = '0';
		vars->game->map_array[vars->game->p_y][vars->game->p_x + 1] = 'P';
		vars->game->p_x = vars->game->p_x + 1;
		vars->game->priority = 1;
		vars->game->img_p = PER_R;
		vars->game->steps++;
		ft_putnbr_fd(vars->game->steps, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_top(t_vars *vars)
{
	if (vars->game->map_array[vars->game->p_y - 1][vars->game->p_x] != '1')
	{
		if (vars->game->map_array[vars->game->p_y - 1][vars->game->p_x] == 'C')
			vars->game->colle++;
		if (vars->game->map_array[vars->game->p_y - 1][vars->game->p_x] == 'E')
		{
			if (collected(vars))
				ft_close(vars);
			else
				return ;
		}
		vars->game->map_array[vars->game->p_y][vars->game->p_x] = '0';
		vars->game->map_array[vars->game->p_y - 1][vars->game->p_x] = 'P';
		vars->game->p_y = vars->game->p_y - 1;
		vars->game->priority = 1;
		vars->game->img_p = PER_T;
		vars->game->steps++;
		ft_putnbr_fd(vars->game->steps, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_bottom(t_vars *vars)
{
	if (vars->game->map_array[vars->game->p_y + 1][vars->game->p_x] != '1')
	{
		if (vars->game->map_array[vars->game->p_y + 1][vars->game->p_x] == 'C')
			vars->game->colle++;
		if (vars->game->map_array[vars->game->p_y + 1][vars->game->p_x] == 'E')
		{
			if (collected(vars))
				ft_close(vars);
			else
				return ;
		}
		vars->game->map_array[vars->game->p_y][vars->game->p_x] = '0';
		vars->game->map_array[vars->game->p_y + 1][vars->game->p_x] = 'P';
		vars->game->p_y = vars->game->p_y + 1;
		vars->game->priority = 1;
		vars->game->img_p = PER_B1;
		vars->game->steps++;
		ft_putnbr_fd(vars->game->steps, 1);
		ft_putchar_fd('\n', 1);
	}
}
