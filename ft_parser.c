/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:41:29 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/30 15:34:19 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

static int	in_set(const char *set, char c)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

static t_format	*init_format(void)
{
	t_format	*frmt;

	frmt = malloc(sizeof(t_format));
	if (!frmt)
		return (0);
	ft_bzero(frmt, sizeof(t_format));
	frmt->precision = -1;
	return (frmt);
}

static void	get_flags(t_format *spec, char c)
{
	if (c == '-')
		spec->minus = 1;
	else if (c == '0')
		spec->zero = 1;
	else if (c == '#')
		spec->hash = 1;
	else if (c == ' ')
		spec->space = 1;
	else if (c == '+')
		spec->plus = 1;
}

t_format	*ft_parse_specifiers(const char *frmt, int *i)
{
	t_format	*spec;

	spec = init_format();
	if (!spec)
		return (0);
	while (in_set("-0# +", frmt[*i]))
	{
		get_flags(spec, frmt[*i]);
		(*i)++;
	}
	if (ft_isdigit(frmt[*i]))
		spec->width = ft_atoi(&frmt[*i]);
	while (ft_isdigit(frmt[*i]))
		(*i)++;
	if (frmt[*i] == '.')
	{
		(*i)++;
		spec->precision = ft_atoi(&frmt[*i]);
		if (spec->precision < 0)
			spec->presision = 0;
		while (ft_isdigit(frmt[*i]))
			(*i)++;
	}
	spec->conversion = frmt[(*i)++];
	return (spec);
}
