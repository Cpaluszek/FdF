/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:07:51 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/29 16:26:43 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Note: what is case_size_z  and z_size
/*
	- mlx			= current MLX instance
	- mlx_win		= mlx window instance
	- mlx_loop()	= initiate window rendering
*/

// TODO: mlx events
// ? MLX pointer ?
int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	*map;

	if (argc < 2)
		manage_errors(0, argv[0]);
	map = malloc(sizeof(t_map));
	if (map == NULL)
		manage_errors(3, "");
	ft_parse_map(argv[1], map);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	mlx.img.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, \
		&mlx.img.line_length, &mlx.img.endian);
	ft_print_map(map);
	draw_wireframe(map, &mlx);
	mlx_loop(mlx.mlx);
	ft_free_map(map);
	return (0);
}

// TODO: MLX hooks
/*	Setup MLX hooks
	- ESC				-> close window
	- Red Cross clicked	-> close window
	- Window is resize	-> print in terminal
*/
void	setup_mlx_hooks(t_mlx *mlx)
{
	// mlx_hook(mlx->win, ON_KEYDOWN, 1L << 0, keyboard_hooks, mlx);
	mlx_key_hook(mlx->win, keyboard_hooks, mlx);
}
