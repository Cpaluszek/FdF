/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:56:08 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 11:16:06 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_PLUS || key == SCROLL_UP)
		fdf->cam->zoom *= 1.05f;
	else if (key == NUM_PAD_MINUS || key == SCROLL_DOWN)
		fdf->cam->zoom *= 0.95f;
	draw_wireframe(fdf);
}

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

void	rotate(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_2)
		fdf->cam->alpha += .05f;
	else if (key == NUM_PAD_8)
		fdf->cam->alpha -= .05f;
	if (key == NUM_PAD_4)
		fdf->cam->beta -= .05f;
	else if (key == NUM_PAD_6)
		fdf->cam->beta += .05f;
	if (key == NUM_PAD_1)
		fdf->cam->gamma += .05f;
	else if (key == NUM_PAD_3)
		fdf->cam->gamma -= .05f;
	draw_wireframe(fdf);
}

void	reset_rotations(t_fdf *fdf)
{
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
}
