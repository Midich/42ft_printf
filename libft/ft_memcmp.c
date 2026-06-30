/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:58:53 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/26 18:01:57 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*char_s1 = s1;
	const unsigned char	*char_s2 = s2;
	int					diff;	

	if (!n || s1 == s2)
		return (0);
	while (n--)
	{
		diff = *(char_s1++) - *(char_s2++);
		if (diff)
			return (diff);
	}
	return (0);
}
