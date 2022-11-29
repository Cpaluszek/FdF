/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:28:20 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/29 16:29:47 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// NOTE: ?????????????????
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

#include <stdio.h>
int	keyboard_hooks(int key, t_mlx *mlx)
{
	(void) mlx;
	printf("key = %d\n", key);
	ft_printf("key = %d\n", key);
	return (0);
}
	// mlx_destroy_window(mlx->mlx, mlx->win);
