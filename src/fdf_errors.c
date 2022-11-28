/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:58:17 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/28 18:43:27 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// Todo: manage error codes (return -1 everytime something is wrong ?)

/* Print error message and interrupt program
	- 0 -> no arguments
	- 1 -> file not found
	- 2 -> unable to close file
	- 3 -> allocation error
*/
void	manage_errors(int err_no, char *text)
{
	if (err_no == 0)
		ft_printf_fd(STDERR_FILENO,
			"Usage: %s <filename> [ case_size_z z_size ]\n", text);
	else if (err_no == 1)
		ft_printf_fd(STDERR_FILENO, "No file %s\n", text);
	else if (err_no == 2)
		ft_printf_fd(STDERR_FILENO, "Unable to close file %s\n", text);
	else if (err_no == 3)
		ft_printf_fd(STDERR_FILENO, "Allocation error\n");
	exit(-1);
}
