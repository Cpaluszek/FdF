/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:56:08 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/05 14:18:29 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//TODO: set max and min for angle and height mult
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
	if (key == KEY_E)
		fdf->map->angle--;
	else if (key == KEY_Q)
		fdf->map->angle++;
	draw_wireframe(fdf);
}

void	height_mult(int key, t_fdf *fdf)
{
	if (key == RIGHT_ANGLE_BRACKET)
		fdf->map->height_mult++;
	else if (key == LEFT_ANGLE_BRACKET)
		fdf->map->height_mult--;
	draw_wireframe(fdf);
}
