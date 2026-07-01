/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 10:05:45 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 13:33:53 by msowinsk         ###   ########.fr       */
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

	spec = ft_parse_specifiers(frmt, i);
	if (!spec)
		return (0);
	*len += ft_handle_specifiers(spec, ap);
	free(spec);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;

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
