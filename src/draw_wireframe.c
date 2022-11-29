/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:51:30 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/29 16:09:53 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_wireframe(t_map *map, t_mlx *mlx)
{
	(void) map;
	for (int i = 50; i < WIN_WIDTH - 50; i++)
	{
		my_mlx_pixel_put(&mlx->img, i, 50, WHITE);
		my_mlx_pixel_put(&mlx->img, i, WIN_HEIGHT - 50, WHITE);
	}
	for (int i = 50; i < WIN_HEIGHT - 50; i++)
	{
		my_mlx_pixel_put(&mlx->img, 50, i, WHITE);
		my_mlx_pixel_put(&mlx->img, WIN_WIDTH - 50, i, WHITE);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.img, 0, 0);
}
