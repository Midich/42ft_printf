/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:58:40 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/18 15:32:42 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	in_set(const char *set, int c)
{
	while (*set)
	{
		if (*(set++) == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*end;
	char		*new_str;
	char		*new_str_s;

	while (in_set(set, *s1))
		s1++;
	end = s1;
	while (*end)
		end++;
	end--;
	while (in_set(set, *end) && s1 <= end)
		end--;
	new_str = malloc((end - s1) + 2);
	if (!new_str)
		return (0);
	new_str_s = new_str;
	while (s1 <= end)
	{
		*(new_str++) = *(s1++);
	}
	*new_str = 0;
	return (new_str_s);
}
