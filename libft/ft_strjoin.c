/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:44:59 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/27 15:16:10 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*new_str;
	char			*new_str_start;

	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (0);
	new_str_start = new_str;
	while (*s1)
		*(new_str++) = *(s1++);
	while (*s2)
		*(new_str++) = *(s2++);
	*new_str = 0;
	return (new_str_start);
}
