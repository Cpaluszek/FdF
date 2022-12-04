/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:47:10 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/04 15:00:14 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Link events to actions
void	setup_mlx_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, ON_KEYDOWN, 1L << 0, keyboard_hooks, fdf);
	mlx_hook(fdf->win, ON_BUTTON_PRESS, 1L << 0, button_hooks, fdf);
	mlx_mouse_hook(fdf->win, mouse_hooks, fdf);
}

//TODO: remove printf on keys
//TODO: set max and min for angle and height mult
// NOTE: define increments in header
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
	else if (key == KEY_E)
		fdf->map->angle--;
	else if (key == KEY_Q)
		fdf->map->angle++;
	else if (key == NUM_PLUS)
		fdf->map->zoom *= 1.05f;
	else if (key == NUM_DOWN)
		fdf->map->zoom *= 0.95f;
	else if (key == KEY_W)
		fdf->map->shift_y += 10;
	else if (key == KEY_A)
		fdf->map->shift_x += 10;
	else if (key == KEY_S)
		fdf->map->shift_y -= 10;
	else if (key == KEY_D)
		fdf->map->shift_x -= 10;
	else
	{
		ft_printf("key = %d\n", key);
		return (0);
	}
	draw_wireframe(fdf);
	return (0);
}

// Red cross clicked event
int	button_hooks(t_fdf *mlx)
{
	exit_fdf(mlx);
	return (0);
}

// Todo: on mouse scroll zoom and center bellow cursor
int	mouse_hooks(int key, int x, int y, t_fdf *fdf)
{
	(void) x;
	(void) y;
	if (key == SCROLL_DOWN)
		fdf->map->zoom *= 0.95f;
	else if (key == SCROLL_UP)
		fdf->map->zoom *= 1.05f;
	else
	{
		ft_printf("key = %d\n", key);
		return (0);
	}
	draw_wireframe(fdf);
	return (0);
}