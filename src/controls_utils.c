/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:56:08 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 09:56:07 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_PLUS || key == SCROLL_UP)
		fdf->map->zoom *= 1.05f;
	else if (key == NUM_PAD_MINUS || key == SCROLL_DOWN)
		fdf->map->zoom *= 0.95f;
	draw_wireframe(fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == KEY_W)
		fdf->map->shift_y += 10;
	else if (key == KEY_A)
		fdf->map->shift_x += 10;
	else if (key == KEY_S)
		fdf->map->shift_y -= 10;
	else if (key == KEY_D)
		fdf->map->shift_x -= 10;
	draw_wireframe(fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_2)
		fdf->map->alpha += .05f;
	else if (key == NUM_PAD_8)
		fdf->map->alpha -= .05f;
	if (key == NUM_PAD_4)
		fdf->map->beta -= .05f;
	else if (key == NUM_PAD_6)
		fdf->map->beta += .05f;
	if (key == NUM_PAD_1)
		fdf->map->gamma += .05f;
	else if (key == NUM_PAD_3)
		fdf->map->gamma -= .05f;
	draw_wireframe(fdf);
}

void	height_mult(int key, t_fdf *fdf)
{
	if (key == RIGHT_ANGLE_BRACKET)
		fdf->map->z_mult++;
	else if (key == LEFT_ANGLE_BRACKET)
		fdf->map->z_mult--;
	draw_wireframe(fdf);
}

void	change_projection(int key, t_fdf *fdf)
{
	if (key == KEY_I && fdf->map->projection == PARALLEL)
		fdf->map->projection = ISO;
	else if (key == KEY_P && fdf->map->projection == ISO)
		fdf->map->projection = PARALLEL;
	else
		return ;
	reset_rotations(fdf);
	draw_wireframe(fdf);
}

void	reset_rotations(t_fdf *fdf)
{
	fdf->map->alpha = 0;
	fdf->map->beta = 0;
	fdf->map->gamma = 0;
}
