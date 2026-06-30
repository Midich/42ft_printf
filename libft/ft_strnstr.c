/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:05:34 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/24 15:50:36 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const size_t	little_len = ft_strlen(little);
	size_t			i;

	if (!(*little))
		return ((char *)big);
	while (*big && len && len >= little_len)
	{
		if (*big == *little)
		{
			i = 1;
			while (big[i] && little[i] && i <= len && big[i] == little[i])
			{
				i++;
			}
			if (!little[i])
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (0);
}
