/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:44:57 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/18 16:46:03 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	get_int_len(int n, size_t *len)
{
	int	nn;

	nn = n / 10;
	(*len)++;
	if (nn == 0)
	{
		if (n < 0)
			(*len)++;
		return ;
	}
	get_int_len(nn, len);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	size_t	n_len;
	char	*n_str;

	n_len = 0;
	get_int_len(n, &n_len);
	n_str = ft_calloc(n_len + 1, sizeof(char));
	if (!n_str)
		return (0);
	if (n < 0)
		*n_str = '-';
	n_str[n_len] = 0;
	while (n_len--)
	{
		if (n_str[n_len] == '-')
			break ;
		n_str[n_len] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (n_str);
}
