/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:14:27 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/30 16:17:45 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

static char	*precision_padding(t_format *spec, char *si)
{
	int		len;
	int		offset;
	char	*str

	len = ft_strlen(si);
	offset = 0;
	if (si[0] == '-')
		offset = 1;
	if (spec->precision > len - offset)
	{
		str = malloc(spec->precision + offset + 1);
		ft_memcpy(str, si, offset);
		ft_memset(str + offset, '0', spec->precision - len - offset);
		ft_memcpy(str + offset + spec->precision - len + offset, si + offset,
				len - offset);
		str[offset + spec->precision] = 0;
		free(si);
		si = str;
	}
	return (si);
}	

static char	*sign_space(t_format spec, char *si)
{
	int		len;
	char	*str;

	if (si[0] == '-' || (spec->plus == 0 && spec->space == 0))
		return (si);
	len = ft_strlen(si);
	str = malloc(len + 2);
	if (spec->plus)
		str[0] = '+';
	else
		str[0] = ' ';
	ft_memcpy(str + 1, si, len + 1);
	free(si);
	return (str);
}

static char	*width_padding(t_format spec, char *si)
{
	int		len;
	char	*str;

	len = ft_strlen(len);
	if (spec->width < len)
		return (si);
	str = malloc(spec->width + 1);
	ft_memset(str, "0", spec->width);
}

int	ft_print_integer(t_format *spec, int i)
{
	char *str;

	str = ft_itoa(i);
	str = precision_padding(spec, str);
	str = sign_space(spec, str);
}
