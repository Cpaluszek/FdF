/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:10:47 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/05 16:31:21 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "mlx.h"

# define WIN_HEIGHT		1080
# define WIN_WIDTH		1920
# define MENU_WIDTH		250
# define MENU_HEIGHT	300
# define WIN_NAME		"fdf"

/*	Colors	*/
# define WHITE	0x00FFFFFF
# define RED	0x00FF0000
# define GREEN	0x0000FF00
# define BLUE	0x000000FF

# define TEXT_COLOR			0xEAEAEA
# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E

/*	SOAPY 10 COLOR PALETTE	*/
# define COLOR_P0_0		0x54CEA7
# define COLOR_P0_1		0x2BA4A6
# define COLOR_P0_2		0x0C6987
# define COLOR_P0_3		0x054B84
# define COLOR_P0_4		0x0D2147
# define COLOR_P0_5		0xFFB0BF
# define COLOR_P0_6		0xFF82BD
# define COLOR_P0_7		0xD74AC7
# define COLOR_P0_8		0xA825BA
# define COLOR_P0_9		0x682B9C

/*	NEON SPACE PALETTE	*/
# define COLOR_P1_0		0xDF0772
# define COLOR_P1_1		0xFE546F
# define COLOR_P1_2		0xFF9E7D
# define COLOR_P1_3		0xFFD080
# define COLOR_P1_4		0xFFFDFF
# define COLOR_P1_5		0x0BFFE6
# define COLOR_P1_6		0x01CBCF
# define COLOR_P1_7		0x0188A5
# define COLOR_P1_8		0x3E3264
# define COLOR_P1_9		0x352A55

/*	SWEET 10 PALETTE	*/
# define COLOR_P2_0		0xFFFBEF
# define COLOR_P2_1		0xFFCDCD
# define COLOR_P2_2		0xF6857D
# define COLOR_P2_3		0xBD4B6C
# define COLOR_P2_4		0x852646
# define COLOR_P2_5		0x391F46
# define COLOR_P2_6		0x1BCD8D
# define COLOR_P2_7		0x028FA0
# define COLOR_P2_8		0x32D5FF
# define COLOR_P2_9		0xC4FFFB

/*	HYPERCHILL-10 PALETTE	*/
# define COLOR_P3_0		0xFFB845
# define COLOR_P3_1		0xFB7974
# define COLOR_P3_2		0xF97698
# define COLOR_P3_3		0xCE5F9F
# define COLOR_P3_4		0xA348A6
# define COLOR_P3_5		0x8549AD
# define COLOR_P3_6		0x674AB3
# define COLOR_P3_7		0x556DC8
# define COLOR_P3_8		0x6783DB
# define COLOR_P3_9		0x7998EE

/*	REGAL10 PALETTE	*/
# define COLOR_P4_0		0xE8C170
# define COLOR_P4_1		0xDE9E41
# define COLOR_P4_2		0xBE772b
# define COLOR_P4_3		0x884B2B
# define COLOR_P4_4		0x602C2C
# define COLOR_P4_5		0xDF84A5
# define COLOR_P4_6		0xC65197
# define COLOR_P4_7		0xA23E8C
# define COLOR_P4_8		0x7A367B
# define COLOR_P4_9		0x2B2042

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