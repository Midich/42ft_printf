/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:32:43 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 16:29:53 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_print_uinteger(t_spec *spec, unsigned int i)
{
	char	*str;
	int		len;

	str = ft_utoa(i);
	if (!str)
		return (-1);
	if (spec->precision == 0 && i == 0)
		str[0] = 0;
	str = ft_format_precision(spec, str);
	if (!str)
		return (-1);
	str = ft_format_width(spec, str);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
