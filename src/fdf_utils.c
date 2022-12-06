/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:00:44 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 13:55:36 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>


void	set_default_cam_parameters(t_camera *cam, t_map *map)
{
	cam->angle = 0;
	cam->zoom = ft_min((WIN_WIDTH - MENU_WIDTH) / map->width, \
		WIN_HEIGHT / map->length);
	cam->shift_x = WIN_WIDTH / 2 + MENU_WIDTH / 6;
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

t_point	new_point(int x, int y, int z, t_map *map)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = get_color(point.z, map);
	return (point);
}
