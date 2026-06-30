/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:46:04 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/18 15:43:45 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *nptr)
{
	int		neg;
	long	acc;

	acc = 0;
	neg = 1;
	while (ft_isspace(*nptr))
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*(nptr++) == '-')
			neg = -1;
	}
	while (*nptr && ft_isdigit(*nptr))
	{
		acc = (acc * 10) + (*(nptr++) - '0');
	}
	return (acc * neg);
}
