/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldiaz-ra <ldiaz-ra@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:06:06 by ldiaz-ra          #+#    #+#             */
/*   Updated: 2023/11/27 11:07:28 by ldiaz-ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_matrix(char **memory)
{
	size_t	y;

	y = 0;
	while (memory[y])
	{
		free(memory[y]);
		y++;
	}
	free(memory);
	return (NULL);
}
