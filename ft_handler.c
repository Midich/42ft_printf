/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 12:31:21 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 16:29:53 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_handle_specifiers(t_spec *spec, va_list ap)
{
	if (spec->conversion == '%')
		return (write(1, "%", 1));
	if (spec->conversion == 'c')
		return (ft_print_character(spec, va_arg(ap, int)));
	if (spec->conversion == 's')
		return (ft_print_string(spec, va_arg(ap, char *)));
	if (spec->conversion == 'p')
		return (ft_print_hex(spec, va_arg(ap, unsigned long int)));
	if (spec->conversion == 'd' || spec->conversion == 'i')
		return (ft_print_integer(spec, va_arg(ap, int)));
	if (spec->conversion == 'u')
		return (ft_print_uinteger(spec, va_arg(ap, unsigned int)));
	if (spec->conversion == 'x')
		return (ft_print_hex(spec, va_arg(ap, unsigned int)));
	if (spec->conversion == 'X')
		return (ft_print_hex(spec, va_arg(ap, unsigned int)));
	return (0);
}
