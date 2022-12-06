/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 08:53:35 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 14:24:04 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z, t_map *map)
{
	double	percentage;

	percentage = percent(map->min_z, map->max_z, z);
	if (percentage < 0.1f)
		return (COLOR_P0_0);
	else if (percentage < 0.2f)
		return (COLOR_P0_1);
	else if (percentage < 0.3f)
		return (COLOR_P0_2);
	else if (percentage < 0.4f)
		return (COLOR_P0_3);
	else if (percentage < 0.5f)
		return (COLOR_P0_4);
	else if (percentage < 0.6f)
		return (COLOR_P0_5);
	else if (percentage < 0.7f)
		return (COLOR_P0_6);
	else if (percentage < 0.8f)
		return (COLOR_P0_7);
	else if (percentage < 0.9f)
		return (COLOR_P0_8);
	else
		return (COLOR_P0_9);
}
