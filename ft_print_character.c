/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_character.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:15:22 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/30 13:55:21 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int ft_print_character(t_format spec, char c)
{
	int	len;

	len = 0;
	if (spec->minus)
	{
		len += write(0, &c, 1);
		while (spec->width-- > 1)
			len += write(0, " ", 1);
	}
	else
	{
		while (spec->width-- > 1)
			len += write(0, " ", 1);
		len += write(0, &c, 1);
	}
	return (len);
}
