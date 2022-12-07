/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:56:08 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/07 10:50:44 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define ZOOM_INC_FACTOR	1.05f
#define ZOOM_DEC_FACTOR	0.95f
#define ANGLE_INC		0.01f
#define TRANSLATION_INC	10
#define HEIGHT_MULT_INC	1

// Update zoom settings
void	zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_PLUS || key == SCROLL_UP)
		fdf->cam->zoom *= ZOOM_INC_FACTOR;
	else if (key == NUM_PAD_MINUS || key == SCROLL_DOWN)
		fdf->cam->zoom *= ZOOM_DEC_FACTOR;
	draw_wireframe(fdf);
}

// Update translation settings
void	move(int key, t_fdf *fdf)
{
	if (key == KEY_W)
		fdf->cam->shift_y += TRANSLATION_INC;
	else if (key == KEY_A)
		fdf->cam->shift_x += TRANSLATION_INC;
	else if (key == KEY_S)
		fdf->cam->shift_y -= TRANSLATION_INC;
	else if (key == KEY_D)
		fdf->cam->shift_x -= TRANSLATION_INC;
	draw_wireframe(fdf);
}

// Update rotation settings
void	rotate(int key, t_fdf *fdf)
{
	if (key == KEY_E)
		fdf->cam->angle += ANGLE_INC;
	else if (key == KEY_Q)
		fdf->cam->angle -= ANGLE_INC;
	draw_wireframe(fdf);
}

// Update height modifier setttings
void	height_mult(int key, t_fdf *fdf)
{
	if (key == RIGHT_ANGLE_BRACKET)
		fdf->cam->z_mult += HEIGHT_MULT_INC;
	else if (key == LEFT_ANGLE_BRACKET)
		fdf->cam->z_mult -= HEIGHT_MULT_INC;
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
