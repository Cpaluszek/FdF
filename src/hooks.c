/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:47:10 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/07 09:31:45 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	keyboard_hooks(int key, t_fdf *fdf);
static int	button_hooks(t_fdf *mlx);
static int	mouse_hooks(int key, int x, int y, t_fdf *fdf);

// Link events to actions
// Keyboard events
// Mouse events
// Window frame cross clicked
void	setup_mlx_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, ON_KEYDOWN, 1L << 0, keyboard_hooks, fdf);
	mlx_hook(fdf->win, ON_BUTTON_PRESS, 1L << 0, button_hooks, fdf);
	mlx_mouse_hook(fdf->win, mouse_hooks, fdf);
}

// NOTE: define increments in header
// Detect key press and call needed function
static int	keyboard_hooks(int key, t_fdf *fdf)
{
	if (key == ESC)
		exit_fdf(fdf, 0);
	else if (key == SPACE)
	{
		set_default_cam_parameters(fdf->cam, fdf->map);
		draw_wireframe(fdf);
	}
	else if (key == RIGHT_ANGLE_BRACKET || key == LEFT_ANGLE_BRACKET)
		height_mult(key, fdf);
	else if (key == KEY_Q || key == KEY_E)
		rotate(key, fdf);
	else if (key == NUM_PAD_PLUS || key == NUM_PAD_MINUS)
		zoom(key, fdf);
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		change_projection(key, fdf);
	else if (key == KEY_1 || key == KEY_2 || key == KEY_3
		|| key == KEY_4 || key == KEY_5)
		pick_color_palette(key, fdf);
	return (0);
}

// Frame cross click
static int	button_hooks(t_fdf *mlx)
{
	exit_fdf(mlx, 0);
	return (0);
}

// Mouse scroll
static int	mouse_hooks(int key, int x, int y, t_fdf *fdf)
{
	(void) x;
	(void) y;
	if (key == SCROLL_DOWN || key == SCROLL_UP)
		zoom(key, fdf);
	return (0);
}
