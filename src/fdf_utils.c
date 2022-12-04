/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:00:44 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/03 09:56:02 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\n---------------- MAP ----------------\n");
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
			ft_printf("%d ", map->grid[i][j++]);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

// Free the current grid and exit program
void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->grid)
	{
		while (i < map->height)
			free(map->grid[i++]);
		free(map->grid);
	}
	free(map);
}
