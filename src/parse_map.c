/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:55:07 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/29 13:13:22 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parse_map(char *path, t_map *map)
{
	t_list	*map_file;
	char	*line;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		manage_errors(1, path);
	ft_read_map_file(fd, &map_file);
	map->height = ft_lstsize(map_file);
	map->width = 0;
	i = -1;
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
	ft_populate_grid(map, map_file, -1);
	if (close(fd) == -1)
		manage_errors(2, path);
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
			while (*line && *line != ' ')
				line++;
			line++;
		}
		map_file = map_file->next;
	}
	ft_lstclear(&head, &free_map_file_content);
}
