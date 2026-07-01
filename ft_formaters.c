/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formaters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 11:51:49 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 14:26:24 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

char	*ft_format_precision(t_spec *spec, char *si)
{
	int		len;
	int		offset;
	int		prec;
	char	*str;

	len = ft_strlen(si);
	offset = 0;
	if (spec->precision < 0)
		return (si);
	prec = spec->precision;
	if (si[0] == '-')
		offset = 1;
	if (prec > len - offset)
	{
		str = malloc(prec + offset + 1);
		ft_memcpy(str, si, offset);
		ft_memset(str + offset, '0', prec - len - offset);
		ft_memcpy(str + offset + prec - len + offset, si + offset,
			len - offset);
		str[offset + prec] = 0;
		free(si);
		si = str;
	}
	return (si);
}

char	*ft_format_sign_space(t_spec *spec, char *si)
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

static char	*zero_padding(t_spec *spec, char *si, int len)
{
	char	*str;
	int		offset;

	offset = 0;
	str = malloc(len + 1);
	if (si[0] == '+' || si[0] == '-')
		offset = 1;
	else if (!ft_memcmp("0x", si, 2))
		offset = 2;
	ft_memcpy(str, si, offset);
	ft_memset(str + offset, '0', spec->width - len);
	ft_memcpy(str + offset + spec->width - len, si + offset,
		len - offset);
	si[spec->width] = 0;
	free(si);
	return (str);
}

char	*ft_format_width(t_spec *spec, char *si)
{
	int		len;
	char	*str;

	len = ft_strlen(si);
	if (spec->width < len)
		return (si);
	str = malloc(spec->width + 1);
	if (spec->zero && !(spec->minus || spec->precision >= 0))
		return (zero_padding(spec, si, len));
	str = malloc(len + 1);
	if (spec->minus)
	{
		ft_memcpy(str, si, len);
		ft_memset(str + len, ' ', spec->width - len);
	}
	else
	{
		ft_memset(str, ' ', spec->width - len);
		ft_memcpy(str + spec->width - len, si, len);
	}
	str[spec->width] = 0;
	free(si);
	return (str);
}
