/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:08:14 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/07 09:08:53 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Update map maximum and minimm
void	ft_check_extremums(t_map *map, int depth)
{
	if (depth > map->max_z)
		map->max_z = depth;
	if (depth < map->min_z)
		map->min_z = depth;
}

// Create a new point structure and pick color depending on its z value
t_point	new_point(int x, int y, int z, t_map *map)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.color = get_color(point.z, map);
	return (point);
}
