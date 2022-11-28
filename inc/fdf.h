/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:07:20 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/28 18:41:29 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <fcntl.h>

typedef struct s_map
{
	int	height;
	int	width;
	int	**grid;
}	t_map;

void	ft_parse_map(char *path, t_map *map);
void	ft_read_map_file(int fd, t_list **map_content);
void	ft_populate_grid(t_map *map, t_list *map_content);

// Todo: remove debug functions
void	ft_print_map(t_map *map);

/*	Errors	*/
void	manage_errors(int err_no, char *text);

/*	Utils	*/
void	ft_free_map(t_map *map);
void	free_map_file_content(void *content);

#endif
