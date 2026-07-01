/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:14:27 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 16:29:53 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_print_integer(t_spec *spec, int i)
{
	char	*str;
	int		len;

	str = ft_itoa(i);
	if (!str)
		return (-1);
	str = ft_format_precision(spec, str);
	if (!str)
		return (-1);
	str = ft_format_sign_space(spec, str);
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
