/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:07:51 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 09:53:28 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc < 2)
		manage_errors(0, argv[0]);
	fdf.map = malloc(sizeof(t_map));
	if (fdf.map == NULL)
		manage_errors(3, "map allocation failed");
	ft_parse_map(argv[1], fdf.map);
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	setup_mlx_hooks(&fdf);
	fdf.data.img = mlx_new_image(fdf.mlx, WIN_WIDTH, WIN_HEIGHT);
	fdf.data.addr = mlx_get_data_addr(fdf.data.img, \
		&fdf.data.bits_per_pixel, &fdf.data.line_length, &fdf.data.endian);
	draw_wireframe(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
	// ft_print_map(fdf.map);

// NOTE: mlx_loop_hook ?
/*	//TODO: Setup MLX hooks
	- ESC				-> close window
	- Red Cross clicked	-> close window
	- Window is resize	-> print in terminal
*/

void	exit_fdf(t_fdf	*mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->data.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_free_map(mlx->map);
	exit(0);
}
