/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:09:30 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/18 13:41:26 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	uc1;
	unsigned char	uc2;

	if (n == 0)
		return (0);
	while (n--)
	{
		uc1 = *s1++;
		uc2 = *s2++;
		if (uc1 != uc2)
		{
			return (uc1 - uc2);
		}
		if (uc1 == 0)
			return (0);
	}
	return (0);
}
