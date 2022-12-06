/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:00:44 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 11:11:53 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

// void	ft_print_map(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	ft_printf("\n---------------- MAP ----------------\n");
// 	while (i < map->length)
// 	{
// 		j = 0;
// 		while (j < map->width)
// 			ft_printf("%d ", map->grid[i][j++]);
// 		ft_printf("\n");
// 		i++;
// 	}
// 	ft_printf("\n");
// }

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

void	set_default_cam_parameters(t_camera *cam, t_map *map)
{
	cam->alpha = 0;
	cam->beta = 0;
	cam->gamma = 0;
	cam->zoom = ft_min((WIN_WIDTH - MENU_WIDTH) / map->width, \
		WIN_HEIGHT / map->length);
	cam->shift_x = WIN_WIDTH / 2;
	cam->shift_y = WIN_HEIGHT / 2;
	cam->z_mult = INITIAL_HEIGHT_MULT;
	cam->projection = ISO;
}

void	ft_check_extremums(t_map *map, int depth)
{
	if (depth > map->max_z)
		map->max_z = depth;
	if (depth < map->min_z)
		map->min_z = depth;
}

// TODO. swap other params
void	swap_points(t_point *p1, t_point *p2)
{
	float	temp;

	temp = p1->x;
	p1->x = p2->x;
	p2->x = temp;
	temp = p1->y;
	p1->y = p2->y;
	p2->y = temp;
}
