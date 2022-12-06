/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:55:38 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 18:32:55 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

// Project point in 3D space
// Apply zoom, translation, rotation and projection
void	project(t_fdf *fdf, t_point *p)
{
	p->x -= fdf->map->width / 2;
	p->y -= fdf->map->length / 2;
	p->x *= fdf->cam->zoom;
	p->y *= fdf->cam->zoom;
	rotate_z(p, fdf->cam->angle);
	if (fdf->cam->projection == ISO)
		isometric_projection(fdf, p);
	else
		parallel_projection(fdf, p);
	p->x += fdf->cam->shift_x;
	p->y += fdf->cam->shift_y;
}

// TODO: adjust /50 division
// Isometric projection
void	isometric_projection(t_fdf *fdf, t_point *p)
{
	p->x = cos(0.8f) * (p->x - p->y);
	p->y = sin(0.8f) * (p->x + p->y) \
		- (p->z * fdf->cam->z_mult * fdf->cam->zoom / 50);
}

// TODO; try conic projection
// Parallel projection
void	parallel_projection(t_fdf *fdf, t_point *p)
{
	float	x;
	float	y;

	x = p->x;
	y = p->y;
	p->x = y + cos(0.8f) * x;
	p->y = sin(0.8f) * x
		- (p->z * fdf->cam->z_mult * fdf->cam->zoom / 50);
}

// Todo: try to rotate around screen center
// Rotation around z axis
void	rotate_z(t_point *p, float angle)
{
	float	x;
	float	y;

	x = p->x;
	y = p->y;
	p->x = (x * cos(angle)) - (y * sin(angle));
	p->y = (x * sin(angle)) + (y * cos(angle));
}
