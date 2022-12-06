/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:07:20 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 10:27:52 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx_utils.h"
# include <fcntl.h>

# define INITIAL_ZOOM			50
# define INITIAL_ANGLE			45
# define INITIAL_HEIGHT_MULT	2

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef enum e_projection
{
	ISO,
	PARALLEL
}	t_projection;

// Note: use vectors for height-width / min-max
// Note: sub structure for position / camera settings
// Note: camera auto scroll on specific key press ?
typedef struct s_map
{
	int				length;
	int				width;
	int				max_z;
	int				min_z;
	unsigned int	color;
	int				**grid;
}	t_map;

typedef struct s_camera
{
	float			zoom;
	int				shift_x;
	int				shift_y;
	int				z_mult;
	double			alpha;
	double			beta;
	double			gamma;
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
void	ft_parse_map(char *path, t_map *map, t_camera *cam);
void	ft_read_map_file(int fd, t_list **map_content);
void	ft_populate_grid(t_map *map, t_list *map_content, int i);
void	ft_check_extremums(t_map *map, int depth);
void	ft_init_map(t_map *map, t_list *map_file, int height);
void	set_default_cam_parameters(t_camera *cam, t_map *map);

/*	Drawing	*/
void	draw_wireframe(t_fdf *mlx);
void	draw_line(t_fdf *mlx, t_point p1, t_point p2);
int		check_bounds(const t_point p);
void	project(t_fdf *fdf, t_point *p, int z);

/* 	Projections	*/
void	isometric_projection(t_fdf *mlx, t_point *p, int z);
void	parallel_projection(t_fdf *fdf, t_point *p, int z);

/*	Rotations	*/
void	rotate_x(float *y, float *z, double alpha);
void	rotate_y(float *x, float *z, double beta);
void	rotate_z(float *x, float *y, double gamma);

/*	Menu	*/
void	print_menu(t_fdf *fdf);

/*	Errors	*/
void	manage_errors(int err_no, char *text);

/*	Events	*/
void	setup_mlx_hooks(t_fdf *mlx);
int		keyboard_hooks(int key, t_fdf *mlx);
int		button_hooks(t_fdf *mlx);
int		mouse_hooks(int key, int x, int y, t_fdf *fdf);

/*	Controls Utils	*/
void	zoom(int key, t_fdf *fdf);
void	move(int key, t_fdf *fdf);
void	rotate(int key, t_fdf *fdf);
void	height_mult(int key, t_fdf *fdf);
void	change_projection(int key, t_fdf *fdf);
void	reset_rotations(t_fdf *fdf);

/*	Utils	*/
void	ft_free_map(t_map *map);
void	free_map_file_content(void *content);
void	exit_fdf(t_fdf	*mlx);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
double	deg_to_rad(int angle);
void	swap_points(t_point *p1, t_point *p2);
int		get_color(int z, t_map *map);
double	percent(int start, int end, int current);


/*	Debug	*/
void	ft_print_map(t_map *map);

#endif
