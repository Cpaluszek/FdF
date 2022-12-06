/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palettes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:09:01 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 18:22:13 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"

// Set color palette presets in t_map struct
void	set_palette_soapy(t_map *map)
{
	map->colors[0] = COLOR_P0_0;
	map->colors[1] = COLOR_P0_1;
	map->colors[2] = COLOR_P0_2;
	map->colors[3] = COLOR_P0_3;
	map->colors[4] = COLOR_P0_4;
	map->colors[5] = COLOR_P0_5;
	map->colors[6] = COLOR_P0_6;
	map->colors[7] = COLOR_P0_7;
	map->colors[8] = COLOR_P0_8;
	map->colors[9] = COLOR_P0_9;
}

void	set_palette_neon_space(t_map *map)
{
	map->colors[0] = COLOR_P1_0;
	map->colors[1] = COLOR_P1_1;
	map->colors[2] = COLOR_P1_2;
	map->colors[3] = COLOR_P1_3;
	map->colors[4] = COLOR_P1_4;
	map->colors[5] = COLOR_P1_5;
	map->colors[6] = COLOR_P1_6;
	map->colors[7] = COLOR_P1_7;
	map->colors[8] = COLOR_P1_8;
	map->colors[9] = COLOR_P1_9;
}

void	set_palette_sweet(t_map *map)
{
	map->colors[0] = COLOR_P2_0;
	map->colors[1] = COLOR_P2_1;
	map->colors[2] = COLOR_P2_2;
	map->colors[3] = COLOR_P2_3;
	map->colors[4] = COLOR_P2_4;
	map->colors[5] = COLOR_P2_5;
	map->colors[6] = COLOR_P2_6;
	map->colors[7] = COLOR_P2_7;
	map->colors[8] = COLOR_P2_8;
	map->colors[9] = COLOR_P2_9;
}

void	set_palette_hyperchill(t_map *map)
{
	map->colors[0] = COLOR_P3_0;
	map->colors[1] = COLOR_P3_1;
	map->colors[2] = COLOR_P3_2;
	map->colors[3] = COLOR_P3_3;
	map->colors[4] = COLOR_P3_4;
	map->colors[5] = COLOR_P3_5;
	map->colors[6] = COLOR_P3_6;
	map->colors[7] = COLOR_P3_7;
	map->colors[8] = COLOR_P3_8;
	map->colors[9] = COLOR_P3_9;
}

void	set_palette_regal(t_map *map)
{
	map->colors[0] = COLOR_P4_0;
	map->colors[1] = COLOR_P4_1;
	map->colors[2] = COLOR_P4_2;
	map->colors[3] = COLOR_P4_3;
	map->colors[4] = COLOR_P4_4;
	map->colors[5] = COLOR_P4_5;
	map->colors[6] = COLOR_P4_6;
	map->colors[7] = COLOR_P4_7;
	map->colors[8] = COLOR_P4_8;
	map->colors[9] = COLOR_P4_9;
}
