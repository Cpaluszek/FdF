/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:51:30 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/03 14:52:07 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	draw_wireframe(t_fdf *fdf)
{
	int	i;
	int	j;
	int	dx;
	int	dy;

	i = 0;
	fdf->data.img = mlx_new_image(fdf->mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf->data.addr = mlx_get_data_addr(fdf->data.img, &fdf->data.bits_per_pixel,\
		&fdf->data.line_length, &fdf->data.endian);
	dx = WIN_WIDTH / (fdf->map->width + 1);
	dy = WIN_HEIGHT / (fdf->map->height + 1);
	while (i < fdf->map->height)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			if (j < fdf->map->width - 1)
				draw_line(fdf, (t_vector){j, i}, (t_vector){j + 1, i});
			if (i < fdf->map->height - 1)
				draw_line(fdf, (t_vector){j, i}, (t_vector){j, i + 1});
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->data.img, 0, 0);
}

// Bresenham line generation
// 	- line is drawn from left to right
void	draw_line(t_fdf *fdf, t_vector p1, t_vector p2)
{
	float	dx;
	float	dy;
	float	max;
	int		z1;
	int		z2;

	//TODO: swap values if they're not in correct order
	z1 = fdf->map->grid[(int)p1.y][(int)p1.x];
	z2 = fdf->map->grid[(int)p2.y][(int)p2.x];
	//--------zoom--------
	p1.x *= fdf->map->zoom;
	p1.y *= fdf->map->zoom;
	p2.x *= fdf->map->zoom;
	p2.y *= fdf->map->zoom;
	//--------color-------
	if (z1 != 0 || z2 != 0)
		fdf->map->color = RED;
	else
		fdf->map->color = WHITE;
	//---------proj-------
	isometric_projection(fdf, &p1, z1);
	isometric_projection(fdf, &p2, z2);
	//-------shift---------
	p1.x += WIN_WIDTH / 3;
	p1.y += WIN_HEIGHT / 3;
	p2.x += WIN_WIDTH / 3;
	p2.y += WIN_HEIGHT / 3;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	max = fmax(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while (check_window_bounds(p1.x, p1.y) && ((int)(p1.x - p2.x) || (int)(p1.y - p2.y)))
	{
		my_mlx_pixel_put(&fdf->data, p1.x, p1.y, fdf->map->color);
		p1.x += dx;
		p1.y += dy;
		if (p1.x > WIN_WIDTH || p1.y > WIN_HEIGHT || p1.x < 0 || p1.y < 0)
			break ;
	}
}

// Isometric projection
void	isometric_projection(t_fdf *fdf, t_vector *p, int z)
{
	p->x = cos(deg_to_rad(fdf->map->angle)) * (p->x - p->y);
	p->y = sin(deg_to_rad(fdf->map->angle)) * (p->x + p->y) - z * fdf->map->height_mult;
}

int	check_window_bounds(float x, float y)
{
	return (!(x >= WIN_WIDTH || y >= WIN_HEIGHT || x <= 0 || y <= 0));
}
