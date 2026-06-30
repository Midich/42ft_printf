/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:57:07 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/17 16:24:33 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*ssrc = src;
	size_t		left;

	left = size;
	if (left != 0)
	{
		while (--left)
		{
			*dst = *src++;
			if (*dst++ == 0)
				break ;
		}
	}
	if (left == 0)
	{
		if (size != 0)
			*dst = 0;
		while (*src++)
			;
	}
	return (src - ssrc - 1);
}
