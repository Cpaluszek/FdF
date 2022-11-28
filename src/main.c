/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:07:51 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/28 18:48:30 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Note: what is case_size_z  and z_size

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc < 2)
		manage_errors(0, argv[0]);
	map = malloc(sizeof(t_map));
	if (map == NULL)
		manage_errors(3, "");
	ft_parse_map(argv[1], map);
	ft_free_map(map);
	return (0);
}
