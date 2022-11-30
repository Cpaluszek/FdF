/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:28:20 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/30 09:47:08 by cpalusze         ###   ########.fr       */
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

// Link events to actions
void	setup_mlx_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, ON_KEYDOWN, 1L << 0, keyboard_hooks, mlx);
	mlx_hook(mlx->win, ON_BUTTON_PRESS, 1L << 0, button_hooks, mlx);
}

// NOTE: format function with event_ prefix
int	keyboard_hooks(int key, t_mlx *mlx)
{
	if (key == ESC)
		exit_fdf(mlx);
	else
		ft_printf("key = %d\n", key);
	return (0);
}

// Red cross clicked event
int	button_hooks(t_mlx *mlx)
{
	exit_fdf(mlx);
	return (0);
}
