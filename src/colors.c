/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:53:35 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/07 08:55:52 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Assigns color to point depending on z value
int	get_color(int z, t_map *map)
{
	double	percentage;

	percentage = percent(map->min_z, map->max_z, z);
	if (percentage < 0.1f)
		return (map->colors[0]);
	else if (percentage < 0.2f)
		return (map->colors[1]);
	else if (percentage < 0.3f)
		return (map->colors[2]);
	else if (percentage < 0.4f)
		return (map->colors[3]);
	else if (percentage < 0.5f)
		return (map->colors[4]);
	else if (percentage < 0.6f)
		return (map->colors[5]);
	else if (percentage < 0.7f)
		return (map->colors[6]);
	else if (percentage < 0.8f)
		return (map->colors[7]);
	else if (percentage < 0.9f)
		return (map->colors[8]);
	else
		return (map->colors[9]);
}

// Switch color palette presets:
// Update map->colors array
void	pick_color_palette(int key, t_fdf *fdf)
{
	if (key == KEY_1)
		set_palette_soapy(fdf->map);
	if (key == KEY_2)
		set_palette_neon_space(fdf->map);
	if (key == KEY_3)
		set_palette_sweet(fdf->map);
	if (key == KEY_4)
		set_palette_hyperchill(fdf->map);
	if (key == KEY_5)
		set_palette_regal(fdf->map);
	update_points_colors(fdf);
	draw_wireframe(fdf);
}

// Reassigns color to points with map->color[]
void	update_points_colors(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map->length)
	{
		j = 0;
		while (j < fdf->map->width)
		{
			fdf->map->points[i][j].color
				= get_color(fdf->map->points[i][j].z, fdf->map);
			j++;
		}
		i++;
	}
}

// Get light for color depending on point position
static int	lerp_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

// Get color between two points
// This function creates linear gradient
int	lerp_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = lerp_light((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	green = lerp_light((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	blue = lerp_light(start.color & 0xFF,
			end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
