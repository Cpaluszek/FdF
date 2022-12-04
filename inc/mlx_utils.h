/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:10:47 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/04 11:43:05 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "mlx.h"

# define WIN_HEIGHT	1200
# define WIN_WIDTH	1600
# define WIN_NAME	"fdf"

/*	Colors	*/
# define WHITE	0x00FFFFFF
# define RED	0x00FF0000

// SCROLL_DOWN = 4,
// SCROLL_UP = 5,
enum	e_keycodes
{
	NUM_PLUS = 69,
	NUM_DOWN = 78,
	SPACE = 49,
	ESC = 53,
	ARROW_UP = 126,
	ARROW_DOWN = 125,
	ARROW_LEFT = 124,
	ARROW_RIGHT = 123
};

enum	e_mlx_events
{
	ON_KEYDOWN = 2,
	ON_BUTTON_PRESS = 17
};

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/*	Utils	*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif