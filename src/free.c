/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:19:13 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 11:33:38 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//TODO: find a better file name
// Free the current grid and exit program
void	free_grid(int **grid, int size)
{
	int	i;

	i = 0;
	if (grid)
	{
		while (i < size)
			free(grid[i++]);
		free(grid);
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->points)
	{
		while (i < map->length)
			free(map->points[i++]);
		free(map->points);
	}
	free(map);
}
