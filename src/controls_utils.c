/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:56:08 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 18:22:57 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Update zoom settings
void	zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_PLUS || key == SCROLL_UP)
		fdf->cam->zoom *= 1.05f;
	else if (key == NUM_PAD_MINUS || key == SCROLL_DOWN)
		fdf->cam->zoom *= 0.95f;
	draw_wireframe(fdf);
}

// Update translation settings
void	move(int key, t_fdf *fdf)
{
	if (key == KEY_W)
		fdf->cam->shift_y += 10;
	else if (key == KEY_A)
		fdf->cam->shift_x += 10;
	else if (key == KEY_S)
		fdf->cam->shift_y -= 10;
	else if (key == KEY_D)
		fdf->cam->shift_x -= 10;
	draw_wireframe(fdf);
}

// Update rotation settings
void	rotate(int key, t_fdf *fdf)
{
	if (key == KEY_E)
		fdf->cam->angle += .01f;
	else if (key == KEY_Q)
		fdf->cam->angle -= .01f;
	draw_wireframe(fdf);
}

// Update height modifier setttings
void	height_mult(int key, t_fdf *fdf)
{
	if (key == RIGHT_ANGLE_BRACKET)
		fdf->cam->z_mult++;
	else if (key == LEFT_ANGLE_BRACKET)
		fdf->cam->z_mult--;
	draw_wireframe(fdf);
}

// Change projection type
void	change_projection(int key, t_fdf *fdf)
{
	if (key == KEY_I && fdf->cam->projection == PARALLEL)
		fdf->cam->projection = ISO;
	else if (key == KEY_P && fdf->cam->projection == ISO)
		fdf->cam->projection = PARALLEL;
	else
		return ;
	draw_wireframe(fdf);
}
