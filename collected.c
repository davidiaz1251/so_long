/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collected.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:23:35 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/24 12:25:25 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collected(t_vars *vars)
{
	return (vars->game->coins == vars->game->collected);
}