/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:57:28 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 15:27:19 by msowinsk         ###   ########.fr       */
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

static char	*add_prefix(char *s)
{
	char	*temp;

	if (!s)
		return (0);
	temp = ft_strjoin("0x", s);
	free(s);
	return (temp);
}

static char	*ft_strmapi_free(char *s, char (*f)(unsigned int, char))
{
	char	*temp;

	if (!s)
		return (0);
	temp = ft_strmapi(s, f);
	free(s);
	return (temp);
}

int	ft_print_hex(t_spec *spec, unsigned long int u)
{
	int		len;
	char	*str;

	str = ft_hextoa(u);
	if (!str)
		return (-1);
	str = ft_format_precision(spec, str);
	if (spec->hash || spec->conversion == 'p')
		str = add_prefix(str);
	if (!str)
		return (-1);
	str = ft_format_width(spec, str);
	if (spec->conversion == 'X')
		str = ft_strmapi_free(str, ft_toupper_wrap);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	write(0, str, len);
	free(str);
	return (len);
}
