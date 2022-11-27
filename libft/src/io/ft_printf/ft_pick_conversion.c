/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:22:02 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/26 15:52:39 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pick_conversion(const char c, va_list args)
{
	if (c == 'd' || c == 'i')
		return (ft_print_decimal(va_arg(args, int)));
	if (c == 's')
		return (ft_print_string(va_arg(args, char *)));
	if (c == 'p')
		return (ft_print_pointer(va_arg(args, size_t)));
	if (c == 'u')
		return (ft_print_unsigned_int(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_print_lower_hex(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_print_upper_hex(va_arg(args, unsigned int)));
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), STDOUT_FILENO);
	else if (c == '%')
		ft_putchar_fd('%', STDOUT_FILENO);
	return (1);
}
