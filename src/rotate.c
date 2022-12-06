/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:16:24 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 10:17:35 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

// Todo: refacto to pointer ? or t_point *
void	rotate_x(float *y, float *z, double alpha)
{
	float	previous_y;

	previous_y = *y;
	*y = (previous_y * cos(alpha)) + (*z * sin(alpha));
	*z = (-previous_y * sin(alpha)) + (*z * cos(alpha));
}

/*
** Rotate coordinate by y axis
*/

void	rotate_y(float *x, float *z, double beta)
{
	float	previous_x;

	previous_x = *x;
	*x = (previous_x * cos(beta)) + (*z * sin(beta));
	*z = (-previous_x * sin(beta)) + (*z * cos(beta));
}

/*
** Rotate coordinate by z axis
*/

void	rotate_z(float *x, float *y, double gamma)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x * cos(gamma)) - (previous_y * sin(gamma));
	*y = (previous_x * sin(gamma)) + (previous_y * cos(gamma));
}
