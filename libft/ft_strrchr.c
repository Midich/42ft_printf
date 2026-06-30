/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:05:01 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/27 16:27:33 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const unsigned char	*p = (unsigned char *)s;
	unsigned char		cc;

	cc = c;
	while (*p)
		p++;
	while (1)
	{
		if (*p == cc)
			return ((char *)p);
		else if (p == (unsigned char *)s)
			return (0);
		p--;
	}
}
