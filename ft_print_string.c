/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:55:51 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 16:29:53 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

int	ft_print_string(t_spec *spec, char *s)
{
	int		len;
	int		size;

	size = 0;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (spec->precision >= 0 && spec->precision < len)
		len = spec->precision;
	if (spec->minus)
	{
		size += write(1, s, len);
		while (spec->width-- > len)
			size += write(1, " ", 1);
	}
	else
	{
		while (spec->width-- > len)
			size += write(1, " ", 1);
		size += write(1, s, len);
	}
	return (size);
}
