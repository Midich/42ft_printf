/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:57:28 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 14:50:28 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

static char	ft_toupper_wrap(unsigned int i, char c)
{
	(void) i;
	return (ft_toupper(c));
}

int	ft_print_hex(t_spec *spec, unsigned long int u)
{
	int		len;
	char	*str;
	char	*temp;

	str = ft_hextoa(u);
	str = ft_format_precision(spec, str);
	if (spec->hash || spec->conversion == 'p')
	{
		temp = ft_strjoin("0x", str);
		free(str);
		str = temp;
	}
	str = ft_format_width(spec, str);
	if (spec->conversion == 'X')
	{
		temp = ft_strmapi(str, ft_toupper_wrap);
		free(str);
		str = temp;
	}
	len = ft_strlen(str);
	write(0, str, len);
	free(str);
	return (len);
}
