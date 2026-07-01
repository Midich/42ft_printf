/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:15:22 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 16:29:53 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_character(t_spec *spec, int c)
{
	int		len;
	char	charc;

	charc = c;
	len = 0;
	if (spec->minus)
	{
		len += write(1, &charc, 1);
		while (spec->width-- > 1)
			len += write(1, " ", 1);
	}
	else
	{
		while (spec->width-- > 1)
			len += write(1, " ", 1);
		len += write(1, &charc, 1);
	}
	return (len);
}
