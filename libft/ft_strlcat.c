/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:57:18 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/23 14:43:10 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	src_len = 0;
	if (size != 0)
	{
		while (src[src_len] && (dst_len + src_len) < (size - 1))
		{
			dst[dst_len + src_len] = src[src_len];
			src_len++;
		}
	}
	if (dst_len < size)
		dst[dst_len + src_len] = '\0';
	while (src[src_len])
		src_len++;
	return (dst_len + src_len);
}
