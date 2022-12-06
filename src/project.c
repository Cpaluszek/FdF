/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:55:38 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 10:17:17 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

// #include <stdio.h>
void	project(t_fdf *fdf, t_vector *p, int z)
{
	p->x -= fdf->map->width / 2;
	p->y -= fdf->map->length / 2;
	rotate_z(&p->x, &p->y, fdf->map->gamma);
	rotate_x(&p->y, (float *)&z, fdf->map->alpha);
	rotate_y(&p->x, (float *)&z, fdf->map->beta);
	p->x *= fdf->map->zoom;
	p->y *= fdf->map->zoom;
	if (fdf->map->projection == ISO)
		isometric_projection(fdf, p, z);
	else
		parallel_projection(fdf, p, z);
	p->x += fdf->map->shift_x;
	p->y += fdf->map->shift_y;
}

// Isometric projection
void	isometric_projection(t_fdf *fdf, t_vector *p, int z)
{
	p->x = cos(0.523599f) * (p->x - p->y);
	p->y = sin(0.523599f) * (p->x + p->y) \
		- (z * fdf->map->z_mult * fdf->map->zoom / 50);
}

void	parallel_projection(t_fdf *fdf, t_vector *p, int z)
{
	float	x;
	float	y;

	x = p->x;
	y = p->y;
	p->x = y + cos(0.523599f) * x;
	p->y = sin(0.523599f) * x \
		- (z * fdf->map->z_mult * fdf->map->zoom / 50);
}
