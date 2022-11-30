/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:07:51 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/30 13:15:09 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Note: what is case_size_z  and z_size
/*
	- mlx			= current MLX instance
	- mlx_win		= mlx window instance
	- mlx_loop()	= initiate window rendering
*/

// NOTE: MLX pointer ?
int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc < 2)
		manage_errors(0, argv[0]);
	mlx.map = malloc(sizeof(t_map));
	if (mlx.map == NULL)
		manage_errors(3, "");
	ft_parse_map(argv[1], mlx.map);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	mlx.img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, \
		&mlx.img.line_length, &mlx.img.endian);
	ft_print_map(mlx.map);
	draw_wireframe(&mlx);
	setup_mlx_hooks(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

// NOTE: mlx_loop_hook ?
/*	//TODO: Setup MLX hooks
	- ESC				-> close window
	- Red Cross clicked	-> close window
	- Window is resize	-> print in terminal
*/

void	exit_fdf(t_mlx	*mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_free_map(mlx->map);
	exit(0);
}
