/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:53:47 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/26 17:37:04 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*cdest;
	const unsigned char	*csrc = (unsigned char *)src;

	cdest = (unsigned char *)dest;
	while (n)
	{
		n--;
		*cdest++ = *csrc++;
	}
	return (dest);
}
