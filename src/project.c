/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:55:38 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/07 11:19:35 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	isometric_projection(t_fdf *fdf, t_point *p);
static void	parallel_projection(t_fdf *fdf, t_point *p);
static void	rotate_z(t_point *p, float angle);

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

// Isometric projection with 60 degrees angle
static void	isometric_projection(t_fdf *fdf, t_point *p)
{
	p->x = cos(1.047f) * (p->x - p->y);
	p->y = sin(1.047f) * (p->x + p->y) \
		- (p->z * fdf->cam->z_mult * fdf->cam->zoom / INITIAL_ZOOM);
}

// Parallel projection at 45 degrees
static void	parallel_projection(t_fdf *fdf, t_point *p)
{
	float	x;
	float	y;

	x = p->x;
	y = p->y;
	p->x = x - p->z * cos(0.7853f);
	p->y = y - sin(0.7853f)
		* (p->z * fdf->cam->z_mult * fdf->cam->zoom / INITIAL_ZOOM);
}

// Rotation around z axis
static void	rotate_z(t_point *p, float angle)
{
	float	x;
	float	y;

	x = p->x;
	y = p->y;
	p->x = (x * cos(angle)) - (y * sin(angle));
	p->y = (x * sin(angle)) + (y * cos(angle));
}
