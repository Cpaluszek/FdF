/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:07:51 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/08 07:54:29 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		manage_errors(&fdf, 1, argv[0]);
	fdf.map = malloc(sizeof(t_map));
	fdf.cam = malloc(sizeof(t_camera));
	if (fdf.map == NULL)
		manage_errors(&fdf, 4, "map allocation failed");
	parse_map(argv[1], &fdf);
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

// Exit program and free allocations
void	exit_fdf(t_fdf *fdf, int code)
{
	if (fdf->cam)
		free(fdf->cam);
	if (code == 2)
	{
		free(fdf->map);
		exit(code);
	}
	if (fdf->map)
		free_map(fdf->map);
	if (fdf->mlx && fdf->data.img)
		mlx_destroy_image(fdf->mlx, fdf->data.img);
	if (fdf->mlx && fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	exit(code);
}
