/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 14:17:15 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/18 15:36:14 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static size_t	count_elements(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static char	**free_list(char **list, size_t count)
{
	while (count--)
		free(*list + count);
	free(list);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	const size_t	list_len = count_elements(s, c);
	size_t			i;
	size_t			next;
	char			**list;

	list = ft_calloc(list_len + 1, sizeof(char *));
	if (!list)
		return (0);
	i = 0;
	while (i < list_len)
	{
		next = 0;
		while (*s && *s == c)
			s++;
		while (s[next] && s[next] != c)
			next++;
		list[i] = ft_substr(s, 0, next);
		if (!list[i])
			return (free_list(list, i));
		s += next;
		i++;
	}
	list[i] = 0;
	return (list);
}
