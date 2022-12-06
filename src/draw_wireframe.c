/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:51:30 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 09:54:49 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

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
	while (i < fdf->map->length)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			if (j < fdf->map->width - 1)
				draw_line(fdf, (t_vector){j, i}, (t_vector){j + 1, i});
			if (i < fdf->map->length - 1)
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
