/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:55:38 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 10:42:56 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

// #include <stdio.h>
void	project(t_fdf *fdf, t_point *p, int z)
{
	p->x -= fdf->map->width / 2;
	p->y -= fdf->map->length / 2;
	rotate_z(&p->x, &p->y, fdf->cam->gamma);
	rotate_x(&p->y, (float *)&z, fdf->cam->alpha);
	rotate_y(&p->x, (float *)&z, fdf->cam->beta);
	p->x *= fdf->cam->zoom;
	p->y *= fdf->cam->zoom;
	if (fdf->cam->projection == ISO)
		isometric_projection(fdf, p, z);
	else
		parallel_projection(fdf, p, z);
	p->x += fdf->cam->shift_x;
	p->y += fdf->cam->shift_y;
}

// Isometric projection
// TODO: adjust /50 division
void	isometric_projection(t_fdf *fdf, t_point *p, int z)
{
	p->x = cos(0.523599f) * (p->x - p->y);
	p->y = sin(0.523599f) * (p->x + p->y) \
		- (z * fdf->cam->z_mult * fdf->cam->zoom / 50);
}

void	parallel_projection(t_fdf *fdf, t_point *p, int z)
{
	float	x;
	float	y;

	x = p->x;
	y = p->y;
	p->x = y + cos(0.523599f) * x;
	p->y = sin(0.523599f) * x \
		- (z * fdf->cam->z_mult * fdf->cam->zoom / 50);
}
