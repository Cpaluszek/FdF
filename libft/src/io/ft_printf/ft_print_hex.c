/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 08:27:07 by cpalusze          #+#    #+#             */
/*   Updated: 2022/11/26 15:52:51 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_lower_hex(size_t nb)
{
	size_t	base_len;

	base_len = ft_strlen(HEX_BASE_LOWER);
	return (ft_print_size_t_base(nb, HEX_BASE_LOWER, base_len));
}

int	ft_print_upper_hex(size_t nb)
{
	size_t	base_len;

	base_len = ft_strlen(HEX_BASE_UPPER);
	return (ft_print_size_t_base(nb, HEX_BASE_UPPER, base_len));
}
