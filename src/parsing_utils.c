/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:08:14 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/07 09:10:57 by cpalusze         ###   ########.fr       */
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

// Set map size
void	get_map_size(t_map *map, t_list *map_file, int length)
{
	char	*line;
	int		i;

	i = 0;
	map->min_z = INT_MAX;
	map->max_z = INT_MIN;
	map->length = length;
	map->width = 0;
	line = (char *) map_file->content;
	while (line[i] && line[i] != '\n')
	{
		while (!ft_isspace(line[i]))
			i++;
		map->width++;
		while (ft_isspace(line[i]))
			i++;
	}
}
