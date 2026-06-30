/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 15:48:47 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/26 16:30:43 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char		cc;
	const unsigned char	*cs;

	cc = c;
	cs = (const unsigned char *)s;
	while (1)
	{
		if (*cs == cc)
			return ((char *)cs);
		else if (*cs == 0)
			return (0);
		cs++;
	}
	return (0);
}
