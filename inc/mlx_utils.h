/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:10:47 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/05 13:06:19 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "mlx.h"

# define WIN_HEIGHT		1200
# define WIN_WIDTH		1600
# define MENU_WIDTH		275
# define MENU_HEIGHT	300
# define WIN_NAME		"fdf"

/*	Colors	*/
# define WHITE	0x00FFFFFF
# define RED	0x00FF0000

# define TEXT_COLOR			0xEAEAEA
# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E

# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

enum	e_keycodes
{
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_Q = 12,
	KEY_W = 13,
	KEY_E = 14,
	LEFT_ANGLE_BRACKET = 43,
	RIGHT_ANGLE_BRACKET = 47,
	SPACE = 49,
	ESC = 53,
	NUM_PAD_0 = 82,
	NUM_PAD_1 = 83,
	NUM_PAD_2 = 84,
	NUM_PAD_3 = 85,
	NUM_PAD_4 = 86,
	NUM_PAD_5 = 87,
	NUM_PAD_6 = 88,
	NUM_PAD_7 = 89,
	NUM_PAD_8 = 91,
	NUM_PAD_9 = 92,
	NUM_PAD_PLUS = 69,
	NUM_PAD_MINUS = 78,
	ARROW_UP = 126,
	ARROW_DOWN = 125,
	ARROW_LEFT = 124,
	ARROW_RIGHT = 123
};

enum	e_mousecodes
{
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2,
	MOUSE_MIDDLE = 3,
	SCROLL_DOWN = 4,
	SCROLL_UP = 5
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