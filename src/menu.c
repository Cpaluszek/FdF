/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:10:08 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 18:31:03 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "colors.h"

// Todo: polish
// Print menu information on top left corner
void	print_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 65, y += 20, TEXT_COLOR, "Controls:");
	mlx_string_put(mlx, win, 20, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(mlx, win, 20, y += 30, TEXT_COLOR, "Move: WASD");
	mlx_string_put(mlx, win, 20, y += 30, TEXT_COLOR, "Rotate: A/E");
	mlx_string_put(mlx, win, 20, y += 30, TEXT_COLOR, "Flatten: </>");
	mlx_string_put(mlx, win, 20, y += 30, TEXT_COLOR, "Colors: 12345");
	mlx_string_put(mlx, win, 20, y += 30, TEXT_COLOR, "Projection:");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(mlx, win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");
}
