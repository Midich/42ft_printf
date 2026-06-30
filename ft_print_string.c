/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:55:51 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/30 14:14:00 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int	ft_print_string(t_format spec, char *s)
{
	int		len;
	int		size;

	size = 0;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if (spec->precision >= 0 && spec->pecision < len)
		len = spec->precision;
	if (spec->minus)
	{
		size += write(0, s, len);
		while (spec->width-- > len)
			size += write(0, " ", 1);
	}
	else
	{
		while (spec->width-- > len)
			size += write(0, " ", 1);
		size += write(0, s, len);
	}
	return (size);
}
