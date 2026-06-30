/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:53:57 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/27 16:09:24 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*csrc;
	unsigned char		*cdest;

	if (n == 0)
		return (dest);
	if (dest < src)
	{
		csrc = src;
		cdest = dest;
		while (n--)
		{
			*cdest++ = *csrc++;
		}
	}
	else
	{
		csrc = src + (n - 1);
		cdest = dest + (n - 1);
		while (n--)
		{
			*cdest-- = *csrc--;
		}
	}
	return (dest);
}
