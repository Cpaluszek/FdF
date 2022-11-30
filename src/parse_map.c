/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:55:07 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/30 16:56:30 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Parse file content into map structure
void	ft_parse_map(char *path, t_map *map)
{
	t_list	*map_file;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		manage_errors(1, path);
	ft_read_map_file(fd, &map_file);
	ft_init_map(map, map_file, ft_lstsize(map_file));
	ft_populate_grid(map, map_file, -1);
	ft_lstclear(&map_file, &free_map_file_content);
	if (close(fd) == -1)
		manage_errors(2, path);
}

// Init map variables
void	ft_init_map(t_map *map, t_list *map_file, int height)
{
	char	*line;
	int		i;

	i = -1;
	map->height = height;
	map->width = 0;
	map->max_depth = INT_MAX;
	map->min_depth = INT_MIN;
	line = (char *) map_file->content;
	while (line[++i])
		if (line[i] == ' ')
			map->width++;
	map->grid = malloc(sizeof(int *) * map->height);
	if (map->grid == NULL)
	{
		ft_free_map(map);
		manage_errors(3, "map->grid");
	}
}

// NOTE: addback is not optimal
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
			ft_lstclear(map_content, &free_map_file_content);
			manage_errors(3, "file content");
		}
		ft_lstadd_back(map_content, new);
		free(line);
	}
}

// Generate 2D INT array with file content
void	ft_populate_grid(t_map *map, t_list *map_file, int i)
{
	int		j;
	char	*line;
	t_list	*head;

	head = map_file;
	while (++i < map->height)
	{
		map->grid[i] = malloc(sizeof(int) * map->width);
		if (map->grid[i] == NULL)
		{
			ft_free_map(map);
			manage_errors(3, "map->grid[row]");
		}
		j = -1;
		line = map_file->content;
		while (++j < map->width)
		{
			map->grid[i][j] = ft_atoi(line);
			ft_check_extremums(map, map->grid[i][j]);
			while (*line && *line != ' ')
				line++;
			line++;
		}
		map_file = map_file->next;
	}
}

void	ft_check_extremums(t_map *map, int depth)
{
	if (depth > map->max_depth)
		map->max_depth = depth;
	if (depth < map->min_depth)
		map->min_depth = depth;
}
