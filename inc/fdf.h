/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:07:20 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/30 16:59:52 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# define WIN_HEIGHT 800
# define WIN_WIDTH 800
# define WIN_NAME "fdf"
# define WHITE 0x00FFFFFF

// typedef struct s_vector
// {
// 	int	x;
// 	int	y;
// }	t_vector;

typedef struct s_map
{
	int	height;
	int	width;
	int	max_depth;
	int	min_depth;
	int	**grid;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	*map;
}	t_mlx;

enum	e_keycodes
{
	ESC = 53,
};

enum	e_mlx_events
{
	ON_KEYDOWN = 2,
	ON_BUTTON_PRESS = 17
};

/*	Map Parsing	*/
void	ft_parse_map(char *path, t_map *map);
void	ft_read_map_file(int fd, t_list **map_content);
void	ft_populate_grid(t_map *map, t_list *map_content, int i);
void	ft_check_extremums(t_map *map, int depth);
void	ft_init_map(t_map *map, t_list *map_file, int height);

/*	Drawing	*/
void	draw_wireframe(t_mlx *mlx);
void	draw_line(t_mlx *mlx, int x1, int y1, int x2, int y2);

/*	Errors	*/
void	manage_errors(int err_no, char *text);

/*	MLX Utils	*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	setup_mlx_hooks(t_mlx *mlx);
int		keyboard_hooks(int key, t_mlx *mlx);
int		button_hooks(t_mlx *mlx);

/*	Utils	*/
void	ft_free_map(t_map *map);
void	free_map_file_content(void *content);
void	exit_fdf(t_mlx	*mlx);
int		min(int a, int b);
int		max(int a, int b);

// Todo: remove debug functions
/*	Debug	*/
void	ft_print_map(t_map *map);

#endif
