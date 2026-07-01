/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 10:05:45 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 15:04:49 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

static int	print_specifier(const char *frmt, int *i, int *len, va_list ap)
{
	t_spec	*spec;
	int		ret;

	spec = ft_parse_specifiers(frmt, i);
	if (!spec)
		return (0);
	ret = ft_handle_specifiers(spec, ap);
	free(spec);
	if (ret < 0)
		return (0);
	*len += ret;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

	if (!format)
		return (-1);
	va_start(ap, format);
	len = 0;
	i = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!print_specifier(format, &i, &len, ap))
				return (-1);
		}
		else
		{
			len += write(0, &format[i], 1);
			i++;
		}
	}
	va_end(ap);
	return (len);
}
