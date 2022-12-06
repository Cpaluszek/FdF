/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:55:07 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/06 12:51:25 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Parse file content into map structure
void	ft_parse_map(char *path, t_map *map, t_camera *cam)
{
	t_list	*map_file;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		manage_errors(1, path);
	ft_read_map_file(fd, &map_file);
	ft_init_map(map, map_file, ft_lstsize(map_file));
	map->min_z = INT_MAX;
	map->max_z = INT_MIN;
	set_default_cam_parameters(cam, map);
	generate_points(map, map_file);
	if (close(fd) == -1)
		manage_errors(2, path);
}

// Init map variables
void	ft_init_map(t_map *map, t_list *map_file, int height)
{
	char	*line;
	int		i;

	i = 0;
	map->length = height;
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
void	ft_read_map_file(int fd, t_list **map_content)
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
			manage_errors(3, "file content");
		}
		ft_lstadd_back(map_content, new);
		free(line);
	}
}

// Generate 2D INT array with file content
int	**ft_populate_grid(t_map *map, t_list *map_file, int i)
{
	int		**grid;
	int		j;
	char	*line;

	grid = malloc(sizeof(int *) * map->length);
	if (grid == NULL)
	{
		// NOTE: what to free ?
			// check for mallocs in main
		ft_lstclear(&map_file, &free);
		manage_errors(3, "map->grid");
	}
	while (++i < map->length)
	{
		grid[i] = malloc(sizeof(int) * map->width);
		if (grid[i] == NULL)
		{
			free_grid(grid, map->length);
			ft_lstclear(&map_file, &free);
			manage_errors(3, "grid[row]");
		}
		j = -1;
		line = map_file->content;
		while (++j < map->width)
		{
			grid[i][j] = ft_atoi(line);
			ft_check_extremums(map, grid[i][j]);
			while (*line && !ft_isspace(*line))
				line++;
			while (*line && ft_isspace(*line))
				line++;
		}
		map_file = map_file->next;
	}
	return (grid);
}

void	generate_points(t_map *map, t_list *map_file)
{
	int	**grid;
	int	i;
	int	j;

	grid = ft_populate_grid(map, map_file, -1);
	ft_lstclear(&map_file, &free);
	map->points = (t_point **) malloc(sizeof(t_point *) * map->length);
	if (map->points == NULL)
	{
		free_grid(grid, map->length);
		manage_errors(3, "map->points");
	}
	i = 0;
	while (i < map->length)
	{
		map->points[i] = malloc(sizeof(t_point) * map->width);
		if (map->points[i] == NULL)
		{
			free_grid(grid, map->length);
			manage_errors(3, "map->points[row]");
		}
		j = 0;
		while (j < map->width)
		{
			map->points[i][j] = new_point(j, i, grid[i][j], map);
			j++;
		}
		i++;
	}
	free_grid(grid, map->length);
}

//TODO: colors
t_point	new_point(int x, int y, int z, t_map *map)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
	point.color = get_color(point.z, map);
}
