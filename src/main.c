/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:07:51 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/27 14:33:29 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Todo: manage error codes (return -1 everytime something is wrong ?)
// Note: what is case_size_z  and z_siz

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf_fd(STDERR_FILENO,
			"Usage: %s <filename> [ case_size_z z_size ]\n", argv[0]);
		return (0);
	}
	ft_parse_map(argv[1]);
	return (0);
}

void	ft_parse_map(char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf_fd(STDERR_FILENO, "No file %s\n", file_path);
		exit(-1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_printf("%s", line);
		free(line);
	}
}
