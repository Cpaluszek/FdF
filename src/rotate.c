/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:16:24 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 12:38:25 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

// Todo: refacto to pointer ? or t_point *
void	rotate_x(t_point *p, double alpha)
{
	float	y;

	y = p->y;
	p->y = (y * cos(alpha)) + (p->z * sin(alpha));
	p->z = (-y * sin(alpha)) + (p->z * cos(alpha));
}

/*
** Rotate coordinate by y axis
*/

void	rotate_y(t_point *p, double beta)
{
	float	x;

	x = p->x;
	p->x = (x * cos(beta)) + (p->z * sin(beta));
	p->z = (-x * sin(beta)) + (p->z * cos(beta));
}

/*
** Rotate coordinate by z axis
*/

void	rotate_z(t_point *p, double gamma)
{
	float	x;
	float	y;

	x = p->x;
	y = p->y;
	p->x = (x * cos(gamma)) - (y * sin(gamma));
	p->y = (x * sin(gamma)) + (y * cos(gamma));
}
