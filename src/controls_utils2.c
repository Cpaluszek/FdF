/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:15:33 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 11:16:03 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	height_mult(int key, t_fdf *fdf)
{
	if (key == RIGHT_ANGLE_BRACKET)
		fdf->cam->z_mult++;
	else if (key == LEFT_ANGLE_BRACKET)
		fdf->cam->z_mult--;
	draw_wireframe(fdf);
}

void	change_projection(int key, t_fdf *fdf)
{
	if (key == KEY_I && fdf->cam->projection == PARALLEL)
		fdf->cam->projection = ISO;
	else if (key == KEY_P && fdf->cam->projection == ISO)
		fdf->cam->projection = PARALLEL;
	else
		return ;
	reset_rotations(fdf);
	draw_wireframe(fdf);
}
