/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:14:52 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/27 15:03:16 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_left(t_vars *vars)
{
	char	position;

	position = vars->game->map_array[vars->game->p_y][vars->game->p_x - 1];
	if (position != '1')
	{
		if (position == 'C')
			vars->game->colle++;
		if (position == 'E')
		{
			if (collected(vars))
				ft_close(vars);
			else
				return ;
		}
		if (position == 'M')
			ft_close(vars);
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
	char	position;

	position = vars->game->map_array[vars->game->p_y][vars->game->p_x + 1];
	if (position != '1')
	{
		if (position == 'C')
			vars->game->colle++;
		if (position == 'E')
		{
			if (collected(vars))
				ft_close(vars);
			else
				return ;
		}
		if (position == 'M')
			ft_close(vars);
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
	char	position;

	position = vars->game->map_array[vars->game->p_y - 1][vars->game->p_x];
	if (position != '1')
	{
		if (position == 'C')
			vars->game->colle++;
		if (position == 'E')
		{
			if (collected(vars))
				ft_close(vars);
			else
				return ;
		}
		if (position == 'M')
			ft_close(vars);
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
	char	position;

	position = vars->game->map_array[vars->game->p_y + 1][vars->game->p_x];
	if (position != '1')
	{
		if (position == 'C')
			vars->game->colle++;
		if (position == 'E')
		{
			if (collected(vars))
				ft_close(vars);
			else
				return ;
		}
		if (position == 'M')
			ft_close(vars);
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
