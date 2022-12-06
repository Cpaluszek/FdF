/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:28:20 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 18:31:20 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// NOTE: ?????????????????
// Color a specific pixel on image
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// Check if a point is inside window bounds
int	check_bounds(const t_point p)
{
	if (p.x <= MENU_WIDTH && p.y <= MENU_HEIGHT)
		return (0);
	else if ((p.x <= 0 || p.y >= WIN_HEIGHT \
		|| p.x >= WIN_WIDTH || p.y <= 0))
		return (0);
	return (1);
}
