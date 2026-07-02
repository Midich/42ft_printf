/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:55:51 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/02 10:25:14 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>

static int	ft_string_padding(t_spec *spec, char *s, int len)
{
	int	size;

	size = 0;
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

int	ft_print_string(t_spec *spec, char *s)
{
	int		len;
	int		size;

	size = 0;
	if (!s && spec->precision >= 0 && spec->precision < 6)
		return (ft_string_padding(spec, "", 0));
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (spec->precision >= 0 && spec->precision < len)
		len = spec->precision;
	size = ft_string_padding(spec, s, len);
	return (size);
}
