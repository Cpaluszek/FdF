/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:51:30 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/07 09:28:35 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"
#include <math.h>

static void	draw_line(t_fdf *fdf, t_point p1, t_point p2);
static void	draw_background(t_fdf *fdf);
static int	check_bounds(const t_point p);

// Generate render
//  - Draw background
// 	- Draw lines between each neighbouring points
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
				draw_line(fdf, fdf->map->points[i][j],
					fdf->map->points[i][j + 1]);
			if (i < fdf->map->length - 1)
				draw_line(fdf, fdf->map->points[i][j],
					fdf->map->points[i + 1][j]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->data.img, 0, 0);
	print_menu(fdf);
}

// Bresenham algorithm to draw a line between two points
// Create a gradient of color between two points using lerp_color()
static void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	t_point	delta;
	float	max;
	int		color;
	t_point	start_p;

	project(fdf, &p1);
	project(fdf, &p2);
	if (!check_bounds(p1) && check_bounds(p2))
		swap_points(&p1, &p2);
	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;
	max = fmax(fabs(delta.x), fabs(delta.y));
	delta.x /= max;
	delta.y /= max;
	start_p = p1;
	while (check_bounds(p1) && ((int)(p1.x - p2.x) || (int)(p1.y - p2.y)))
	{
		color = lerp_color(p1, start_p, p2, delta);
		my_mlx_pixel_put(&fdf->data, p1.x, p1.y, color);
		p1.x += delta.x;
		p1.y += delta.y;
	}
}

// Fill the image with background color
// A second color is used for menu background
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

// Check if a point is inside window bounds
static int	check_bounds(const t_point p)
{
	if (p.x <= MENU_WIDTH && p.y <= MENU_HEIGHT)
		return (0);
	else if ((p.x <= 0 || p.y >= WIN_HEIGHT \
		|| p.x >= WIN_WIDTH || p.y <= 0))
		return (0);
	return (1);
}
