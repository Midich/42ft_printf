/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:57:49 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/24 17:50:17 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_tolower(int c)
{
	unsigned char	uc;

	if (c == EOF)
		return (c);
	uc = c;
	if (uc >= 'A' && uc <= 'Z')
		return (uc | 32);
	return (uc);
}
