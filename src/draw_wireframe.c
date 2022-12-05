/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:51:30 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/05 16:22:01 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

//NOTE: background color
static void	draw_background(t_fdf *fdf)
{
	int	*image;
	int	i;

	image = (int *)(fdf->data.addr);
	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH)
	{
		if (i % WIN_WIDTH < MENU_WIDTH && i / WIN_WIDTH < MENU_HEIGHT)
			image[i] = MENU_BACKGROUND;
		else
			image[i] = BACKGROUND;
		i++;
	}
}

void	draw_wireframe(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	draw_background(fdf);
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
	print_menu(fdf);
}

// Bresenham line generation
// 	- line is drawn from left to right
// Todo: color gradient
void	draw_line(t_fdf *fdf, t_vector p1, t_vector p2)
{
	float	dx;
	float	dy;
	float	max;
	int		z1;
	int		z2;

	z1 = fdf->map->grid[(int)p1.y][(int)p1.x];
	z2 = fdf->map->grid[(int)p2.y][(int)p2.x];
	project(fdf, &p1, z1);
	project(fdf, &p2, z2);
	if (!check_bounds(p1) && check_bounds(p2))
		swap_points(&p1, &p2);
	fdf->map->color = get_color(ft_max(z1, z2), fdf->map);
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	max = fmax(fabs(dx), fabs(dy));
	dx /= max;
	dy /= max;
	while (check_bounds(p1) && ((int)(p1.x - p2.x) || (int)(p1.y - p2.y)))
	{
		my_mlx_pixel_put(&fdf->data, p1.x, p1.y, fdf->map->color);
		p1.x += dx;
		p1.y += dy;
	}
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1);
	return (placement / distance);
}

int	get_color(int z, t_map *map)
{
	double	percentage;

	percentage = percent(map->min_depth, map->max_depth, z);
	if (percentage < 0.1f)
		return (COLOR_P0_0);
	else if (percentage < 0.2f)
		return (COLOR_P0_1);
	else if (percentage < 0.3f)
		return (COLOR_P0_2);
	else if (percentage < 0.4f)
		return (COLOR_P0_3);
	else if (percentage < 0.5f)
		return (COLOR_P0_4);
	else if (percentage < 0.6f)
		return (COLOR_P0_5);
	else if (percentage < 0.7f)
		return (COLOR_P0_6);
	else if (percentage < 0.8f)
		return (COLOR_P0_7);
	else if (percentage < 0.9f)
		return (COLOR_P0_8);
	else
		return (COLOR_P0_9);
}

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
