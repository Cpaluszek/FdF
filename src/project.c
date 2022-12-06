/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:55:38 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 08:56:58 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	rotate_x(float *y, float *z, double alpha)
{
	float	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

/*
** Rotate coordinate by y axis
*/

static void	rotate_y(float *x, float *z, double beta)
{
	float	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

/*
** Rotate coordinate by z axis
*/

static void	rotate_z(float *x, float *y, double gamma)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void	project(t_fdf *fdf, t_vector *p, int z)
{
	p->x -= fdf->map->width / 2;
	p->y -= fdf->map->height / 2;
	p->x *= fdf->map->zoom;
	p->y *= fdf->map->zoom;
	rotate_x(&p->y, (float *)&z, fdf->map->alpha);
	rotate_y(&p->x, (float *)&z, fdf->map->beta);
	rotate_z(&p->x, &p->y, fdf->map->gamma);
	isometric_projection(fdf, p, z);
	p->x += fdf->map->shift_x;
	p->y += fdf->map->shift_y;
}

// Isometric projection
void	isometric_projection(t_fdf *fdf, t_vector *p, int z)
{
	p->x = cos(0.523599f) * (p->x - p->y);
	p->y = sin(0.523599f) * (p->x + p->y) \
		- (z * fdf->map->height_mult * fdf->map->zoom / 50);
}
