/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:00:44 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/07 09:09:03 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

// Init camera paremeters on reset them on space bar input
void	set_default_cam_parameters(t_camera *cam, t_map *map)
{
	cam->angle = 0;
	cam->zoom = ft_min((WIN_WIDTH - MENU_WIDTH) / map->width, \
		WIN_HEIGHT / map->length);
	cam->shift_x = WIN_WIDTH / 2 + MENU_WIDTH / 6;
	cam->shift_y = WIN_HEIGHT / 2;
	cam->z_mult = INITIAL_HEIGHT_MULT;
	cam->projection = ISO;
	set_palette_soapy(map);
}

// Swap two float value
static void	swap_floats(float *a, float *b)
{
	float	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// Swap to point struct
void	swap_points(t_point *p1, t_point *p2)
{
	int	temp;

	swap_floats(&p1->x, &p2->x);
	swap_floats(&p1->y, &p2->y);
	temp = p1->color;
	p1->color = p2->color;
	p2->color = temp;
	temp = p1->z;
	p1->z = p2->z;
	p2->z = temp;
}
