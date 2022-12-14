/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:58:17 by cpalusze          #+#    #+#             */
/*   Updated: 2022/12/10 08:39:55 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define STDERR 2
// Print error message and call fdf_exit
// 	- 1 -> no arguments
// 	- 2 -> file not found
// 	- 3 -> unable to close file
// 	- 4 -> allocation error
void	manage_errors(t_fdf *fdf, int err_no, char *text)
{
	if (err_no == 1)
	{
		ft_printf_fd(STDERR,
			"Usage: %s <filename>\n", text);
		exit(err_no);
	}
	else if (err_no == 2)
		ft_printf_fd(STDERR, "Unable to read file %s\n", text);
	else if (err_no == 3)
		ft_printf_fd(STDERR, "Unable to close file %s\n", text);
	else if (err_no == 4)
		ft_printf_fd(STDERR, "Allocation error: %s\n", text);
	exit_fdf(fdf, err_no);
}
