/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:00:44 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 09:56:07 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\n---------------- MAP ----------------\n");
	while (i < map->length)
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
		while (i < map->length)
			free(map->grid[i++]);
		free(map->grid);
	}
	free(map);
}

void	set_default_map_parameters(t_map *map)
{
	map->alpha = 0;
	map->beta = 0;
	map->gamma = 0;
	map->zoom = ft_min((WIN_WIDTH - MENU_WIDTH) / map->width, \
		WIN_HEIGHT / map->length);
	map->shift_x = WIN_WIDTH / 2;
	map->shift_y = WIN_HEIGHT / 2;
	map->z_mult = INITIAL_HEIGHT_MULT;
	map->color = WHITE;
	map->projection = ISO;
}

void	ft_check_extremums(t_map *map, int depth)
{
	if (depth > map->max_z)
		map->max_z = depth;
	if (depth < map->min_z)
		map->min_z = depth;
}

void	swap_points(t_vector *p1, t_vector *p2)
{
	float	temp;

	temp = p1->x;
	p1->x = p2->x;
	p2->x = temp;
	temp = p1->y;
	p1->y = p2->y;
	p2->y = temp;
}
