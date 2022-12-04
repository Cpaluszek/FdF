/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:28:20 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/03 15:46:25 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// NOTE: ?????????????????
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// Link events to actions
void	setup_mlx_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, ON_KEYDOWN, 1L << 0, keyboard_hooks, fdf);
	mlx_hook(fdf->win, ON_BUTTON_PRESS, 1L << 0, button_hooks, fdf);
	// mlx_mouse_hook(fdf->win, mouse_hooks, fdf);
}

//TODO: remove printf on keys
//TODO: set max and min for angle and height mult
int	keyboard_hooks(int key, t_fdf *fdf)
{
	if (key == ESC)
		exit_fdf(fdf);
	else if (key == SPACE)
		set_default_map_parameters(fdf->map);
	else if (key == ARROW_UP)
		fdf->map->height_mult++;
	else if (key == ARROW_DOWN)
		fdf->map->height_mult--;
	else if (key == ARROW_LEFT)
		fdf->map->angle--;
	else if (key == ARROW_RIGHT)
		fdf->map->angle++;
	else if (key == NUM_PLUS)
		fdf->map->zoom++;
	else if (key == NUM_DOWN)
		fdf->map->zoom--;
	else
		ft_printf("key = %d\n", key);
	draw_wireframe(fdf);
	return (0);
}

// Red cross clicked event
int	button_hooks(t_fdf *mlx)
{
	exit_fdf(mlx);
	return (0);
}

// int	mouse_hooks(int key, t_fdf *fdf)
// {
// 	if (key == SCROLL_DOWN)
// 		fdf->map->zoom--;
// 	else if (key == SCROLL_UP)
// 		fdf->map->zoom++;
// 	else
// 		ft_printf("key = %d\n", key);
// 	draw_wireframe(fdf);
// 	return (0);
// }

//TODO: move in correct file
	// Todo: set zoom depending on number of points
void	set_default_map_parameters(t_map *map)
{
	map->max_depth = INT_MAX;
	map->min_depth = INT_MIN;
	map->angle = 45;
	map->zoom = 50;
	map->height_mult = 2;
	map->color = WHITE;
}
