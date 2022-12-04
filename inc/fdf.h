/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:07:20 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/03 15:39:50 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx_utils.h"
# include <fcntl.h>
# define WIN_HEIGHT 1000
# define WIN_WIDTH 1200
# define WIN_NAME "fdf"
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000

typedef struct s_vector
{
	float	x;
	float	y;
}	t_vector;

typedef struct s_map
{
	int	height;
	int	width;
	int	max_depth;
	int	min_depth;
	int	height_mult;
	int	zoom;
	int	angle;
	int	color;
	int	**grid;
}	t_map;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_data	data;
	t_map	*map;
}	t_fdf;

/*	Map Parsing	*/
void	ft_parse_map(char *path, t_map *map);
void	ft_read_map_file(int fd, t_list **map_content);
void	ft_populate_grid(t_map *map, t_list *map_content, int i);
void	ft_check_extremums(t_map *map, int depth);
void	ft_init_map(t_map *map, t_list *map_file, int height);
void	set_default_map_parameters(t_map *map);

/*	Drawing	*/
void	draw_wireframe(t_fdf *mlx);
void	draw_line(t_fdf *mlx, t_vector p1, t_vector p2);
void	isometric_projection(t_fdf *mlx, t_vector *p, int z);
int		check_window_bounds(float x, float y);

/*	Errors	*/
void	manage_errors(int err_no, char *text);

/*	Events	*/
void	setup_mlx_hooks(t_fdf *mlx);
int		keyboard_hooks(int key, t_fdf *mlx);
int		button_hooks(t_fdf *mlx);
int		mouse_hooks(int key, t_fdf *fdf);

/*	Utils	*/
void	ft_free_map(t_map *map);
void	free_map_file_content(void *content);
void	exit_fdf(t_fdf	*mlx);
int		min(int a, int b);
int		max(int a, int b);
double	deg_to_rad(int angle);

/*	Debug	*/
void	ft_print_map(t_map *map);

#endif
