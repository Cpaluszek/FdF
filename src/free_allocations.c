/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:19:13 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/08 07:53:02 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Free 2D int array
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

// Free map structure and 2D t_point arrary
void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->points != NULL)
	{
		while (i < map->length)
			free(map->points[i++]);
		free(map->points);
	}
	free(map);
}
