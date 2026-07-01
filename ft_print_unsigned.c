/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:32:43 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 14:31:55 by msowinsk         ###   ########.fr       */
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
	str = ft_format_precision(spec, str);
	str = ft_format_width(spec, str);
	len = ft_strlen(str);
	write(0, str, len);
	free(str);
	return (len);
}
