/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:22:19 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/18 13:37:45 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	const size_t	s_len = ft_strlen(s);
	char			*sub;
	size_t			sub_len;
	size_t			i;

	sub_len = s_len - start;
	if (start >= s_len)
		sub_len = 0;
	else if (sub_len > len)
		sub_len = len;
	sub = malloc(sub_len + 1);
	if (!sub)
		return (0);
	i = 0;
	while (i < sub_len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = 0;
	return (sub);
}
