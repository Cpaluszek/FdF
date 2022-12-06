/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:47:10 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 09:45:04 by cpalusze         ###   ########.fr       */
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
// NOTE: define increments in header
int	keyboard_hooks(int key, t_fdf *fdf)
{
	if (key == ESC)
		exit_fdf(fdf);
	else if (key == SPACE)
	{
		set_default_map_parameters(fdf->map);
		draw_wireframe(fdf);
	}
	else if (key == RIGHT_ANGLE_BRACKET || key == LEFT_ANGLE_BRACKET)
		height_mult(key, fdf);
	else if (key == NUM_PAD_1 || key == NUM_PAD_2
		|| key == NUM_PAD_3 || key == NUM_PAD_4
		|| key == NUM_PAD_4 || key == NUM_PAD_6
		|| key == NUM_PAD_8)
		rotate(key, fdf);
	else if (key == NUM_PAD_PLUS || key == NUM_PAD_MINUS)
		zoom(key, fdf);
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		change_projection(key, fdf);
	else if (key == KEY_R)
		reset_rotations(fdf);
	else
		ft_printf("key = %d\n", key);
	return (0);
}

// Red cross clicked event
int	button_hooks(t_fdf *mlx)
{
	exit_fdf(mlx);
	return (0);
}

// Todo:on mouse scroll zoom and center bellow cursor
int	mouse_hooks(int key, int x, int y, t_fdf *fdf)
{
	(void) x;
	(void) y;
	if (key == SCROLL_DOWN || key == SCROLL_UP)
		zoom(key, fdf);
	else
		ft_printf("key = %d\n", key);
	return (0);
}
