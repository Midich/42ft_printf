/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:47:48 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 14:32:45 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	get_uint_len(unsigned int n, size_t *len)
{
	unsigned int	nn;

	nn = n / 10;
	(*len)++;
	if (nn == 0)
		return ;
	get_uint_len(nn, len);
}

static void	get_hex_len(unsigned long int n, size_t *len)
{
	unsigned long int	nn;

	nn = n >> 4;
	(*len)++;
	if (nn == 0)
		return ;
	get_hex_len(nn, len);
}

char	*ft_utoa(unsigned int n)
{
	size_t	n_len;
	char	*n_str;

	n_len = 0;
	get_uint_len(n, &n_len);
	n_str = ft_calloc(n_len + 1, sizeof(char));
	if (!n_str)
		return (0);
	n_str[n_len] = 0;
	while (n_len--)
	{
		n_str[n_len] = n % 10 + '0';
		n /= 10;
	}
	return (n_str);
}

char	*ft_hextoa(unsigned long int n)
{
	const char	*set = "0123456789abcdef";
	size_t		n_len;
	char		*n_str;

	n_len = 0;
	get_hex_len(n, &n_len);
	n_str = ft_calloc(n_len + 1, sizeof(char));
	if (!n_str)
		return (0);
	n_str[n_len] = 0;
	while (n_len--)
	{
		n_str[n_len] = set[n & 15];
		n >>= 4;
	}
	return (n_str);
}
