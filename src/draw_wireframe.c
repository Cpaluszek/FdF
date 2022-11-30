/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:51:30 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/30 18:14:06 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_wireframe(t_mlx *mlx)
{
	// int	i;
	// int	j;
	int	dx;
	int	dy;
	// int	x;
	// int	y;
	
	dx = WIN_WIDTH / (mlx->map->width + 1);
	dy = WIN_HEIGHT / (mlx->map->height + 1);
	draw_line(mlx, dx, dy, WIN_WIDTH - dx, 400);
	// i = 0;
	// while (i < mlx->map->height - 1)
	// {
	// 	y = (dy * i) + dy;
	// 	j = 0;
	// 	while (j < mlx->map->width - 1)
	// 	{
	// 		x = (dx * j) + dx;
	// 		draw_line(mlx, x, y, x + dx, y);
	// 		draw_line(mlx, x, y, x, y + dy);
	// 		j++;
	// 	}
	// 	i++;
	// }
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}

// Bresenham line generation
// 	- line is drawn from left to right
void	draw_line(t_mlx *mlx, int x1, int y1, int x2, int y2)
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
	int	m_new;
	int	x;
	int slope_error_new;

	x_min = min(x1, x2);
	x_max = max(x1, x2);
	y_min = min(y1, y2);
	y_max = max(y1, y2);
	m_new = 2 * (y2 - y1);
	slope_error_new = m_new - (x_max - x_min);
	x = x_min;
	while (x <= x_max)
	{
		my_mlx_pixel_put(&mlx->img, x, y_min, WHITE);
		slope_error_new += m_new;
		if (slope_error_new >= 0)
		{
			y_min++;
			slope_error_new -= 2 * (x_max - x_min);
		}
		x++;
	}
}
