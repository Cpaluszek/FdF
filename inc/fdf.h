/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:07:20 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/29 16:28:00 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: create different headers

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# define WIN_HEIGHT 800
# define WIN_WIDTH 800
# define WIN_NAME "fdf"
# define WHITE 0x00FFFFF
# define ON_KEYDOWN	2

typedef struct s_map
{
	int	height;
	int	width;
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
}	t_mlx;

void	ft_parse_map(char *path, t_map *map);
void	ft_read_map_file(int fd, t_list **map_content);
void	ft_populate_grid(t_map *map, t_list *map_content, int i);

/*	Drawing	*/
void	draw_wireframe(t_map *map, t_mlx *mlx);

/*	Errors	*/
void	manage_errors(int err_no, char *text);

/*	MLX Utils	*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		keyboard_hooks(int key, t_mlx *mlx);

/*	Utils	*/
void	ft_free_map(t_map *map);
void	free_map_file_content(void *content);

// Todo: remove debug functions
/*	Debug	*/
void	ft_print_map(t_map *map);

#endif
