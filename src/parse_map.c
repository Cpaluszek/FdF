/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:55:07 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/07 09:01:17 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

// Parse file content into map structure
void	ft_parse_map(char *path, t_fdf *fdf)
{
	t_list	*map_file;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		manage_errors(fdf, 2, path);
	ft_read_map_file(fdf, fd, &map_file);
	get_map_size(fdf->map, map_file, ft_lstsize(map_file));
	set_default_cam_parameters(fdf->cam, fdf->map);
	generate_points(fdf, map_file, -1);
	if (close(fd) == -1)
		manage_errors(fdf, 3, path);
}

// Set map size
void	get_map_size(t_map *map, t_list *map_file, int length)
{
	char	*line;
	int		i;

	i = 0;
	map->min_z = INT_MAX;
	map->max_z = INT_MIN;
	map->length = length;
	map->width = 0;
	line = (char *) map_file->content;
	while (line[i] && line[i] != '\n')
	{
		while (!ft_isspace(line[i]))
			i++;
		map->width++;
		while (ft_isspace(line[i]))
			i++;
	}
}

// Read file content and save each line in list
void	ft_read_map_file(t_fdf *fdf, int fd, t_list **map_content)
{
	char	*line;
	t_list	*new;

	*map_content = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		new = ft_lstnew(ft_strdup(line));
		if (new->content == NULL)
		{
			free (line);
			ft_lstclear(map_content, &free);
			manage_errors(fdf, 4, "file content");
		}
		ft_lstadd_back(map_content, new);
		free(line);
	}
}

// Generate 2D INT array with file content
int	**ft_populate_grid(t_fdf *fdf, t_list *map_file, int i)
{
	int		**grid;
	int		j;
	char	*line;

	grid = malloc(sizeof(int *) * fdf->map->length);
	if (grid == NULL)
	{
		ft_lstclear(&map_file, &free);
		manage_errors(fdf, 4, "map->grid");
	}
	while (++i < fdf->map->length)
	{
		grid[i] = malloc(sizeof(int) * fdf->map->width);
		if (grid[i] == NULL)
		{
			free_grid(grid, fdf->map->length);
			ft_lstclear(&map_file, &free);
			manage_errors(fdf, 4, "map->grid[row]");
		}
		j = -1;
		line = map_file->content;
		while (++j < fdf->map->width)
		{
			grid[i][j] = ft_atoi(line);
			ft_check_extremums(fdf->map, grid[i][j]);
			while (*line && !ft_isspace(*line))
				line++;
			while (*line && ft_isspace(*line))
				line++;
		}
		map_file = map_file->next;
	}
	return (grid);
}

// Generate map 2D t_point array
void	generate_points(t_fdf *fdf, t_list *map_file, int i)
{
	int	**grid;
	int	j;

	grid = ft_populate_grid(fdf, map_file, -1);
	ft_lstclear(&map_file, &free);
	fdf->map->points = malloc(sizeof(t_point *) * fdf->map->length);
	if (fdf->map->points == NULL)
	{
		free_grid(grid, fdf->map->length);
		manage_errors(fdf, 4, "map->points");
	}
	while (++i < fdf->map->length)
	{
		fdf->map->points[i] = malloc(sizeof(t_point) * fdf->map->width);
		if (fdf->map->points[i] == NULL)
		{
			free_grid(grid, fdf->map->length);
			manage_errors(fdf, 4, "map->points[row]");
		}
		j = -1;
		while (++j < fdf->map->width)
			fdf->map->points[i][j] = new_point(j, i, grid[i][j], fdf->map);
	}
	free_grid(grid, fdf->map->length);
}
