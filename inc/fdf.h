/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:07:20 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/07 11:01:47 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define INITIAL_ZOOM			50
# define INITIAL_ANGLE			45
# define INITIAL_HEIGHT_MULT	2
# include "libft.h"
# include "mlx_utils.h"

typedef struct s_point
{
	float	x;
	float	y;
	int		z;
	int		color;
}	t_point;

typedef enum e_projection
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct s_map
{
	int		length;
	int		width;
	int		max_z;
	int		min_z;
	int		colors[10];
	t_point	**points;
}	t_map;

typedef struct s_camera
{
	float			zoom;
	int				shift_x;
	int				shift_y;
	int				z_mult;
	float			angle;
	t_projection	projection;
}	t_camera;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_data		data;
	t_map		*map;
	t_camera	*cam;
}	t_fdf;

/*	Map Parsing	*/
void	parse_map(char *path, t_fdf *fdf);
void	check_extremums(t_map *map, int depth);
void	get_map_size(t_map *map, t_list *map_file, int height);
void	set_default_cam_parameters(t_camera *cam, t_map *map);

/*	Drawing	*/
void	draw_wireframe(t_fdf *mlx);
void	project(t_fdf *fdf, t_point *p);

/*	Menu	*/
void	print_menu(t_fdf *fdf);

/*	Errors	*/
void	manage_errors(t_fdf *fdf, int err_no, char *text);

/*	Controls Utils	*/
void	setup_mlx_hooks(t_fdf *mlx);
void	zoom(int key, t_fdf *fdf);
void	move(int key, t_fdf *fdf);
void	rotate(int key, t_fdf *fdf);
void	height_mult(int key, t_fdf *fdf);
void	change_projection(int key, t_fdf *fdf);

/*	Colors	*/
int		get_color(int z, t_map *map);
void	pick_color_palette(int key, t_fdf *fdf);
void	set_palette_soapy(t_map *map);
void	set_palette_neon_space(t_map *map);
void	set_palette_sweet(t_map *map);
void	set_palette_hyperchill(t_map *map);
void	set_palette_regal(t_map *map);
int		lerp_color(t_point current, t_point start, t_point end, t_point delta);

/*	Utils	*/
void	free_grid(int **grid, int size);
void	free_map(t_map *map);
void	exit_fdf(t_fdf	*mlx, int code);
void	swap_points(t_point *p1, t_point *p2);
t_point	new_point(int x, int y, int z, t_map *map);

/*	Math Utils	*/
int		ft_min(int a, int b);
int		ft_max(int a, int b);
float	percent(int start, int end, int current);
double	deg_to_rad(int angle);

#endif
