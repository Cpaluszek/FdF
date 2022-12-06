/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:55:38 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 13:45:59 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

// #include <stdio.h>
void	project(t_fdf *fdf, t_point *p)
{
	p->x -= fdf->map->width / 2;
	p->y -= fdf->map->length / 2;
	p->x *= fdf->cam->zoom;
	p->y *= fdf->cam->zoom;
	rotate_z(p, fdf->cam->gamma);
	if (fdf->cam->projection == ISO)
		isometric_projection(fdf, p);
	else
		parallel_projection(fdf, p);
	p->x += fdf->cam->shift_x;
	p->y += fdf->cam->shift_y;
}

// Isometric projection
// TODO: adjust /50 division
void	isometric_projection(t_fdf *fdf, t_point *p)
{
	p->x = cos(0.8f) * (p->x - p->y);
	p->y = sin(0.8f) * (p->x + p->y) \
		- (p->z * fdf->cam->z_mult * fdf->cam->zoom / 50);
}

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

void	rotate_z(t_point *p, double gamma)
{
	float	x;
	float	y;

	x = p->x;
	y = p->y;
	p->x = (x * cos(gamma)) - (y * sin(gamma));
	p->y = (x * sin(gamma)) + (y * cos(gamma));
}