/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 10:05:45 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/30 13:19:03 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

static int	print_spec(const char *frmt, long *i, long *len, va_list ap)
{
	t_format	spec;

	spec = ft_parse_specifiers(frmt, i);
	if (!spec)
		return (0);
	*len += ft_handle_specifiers(spec, ap);
	free(form);
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
			if (!print_spec(format, &i, &len, ap))
				return (-1);
		}
		else
			len += write(0, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
