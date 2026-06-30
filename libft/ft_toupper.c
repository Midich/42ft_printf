/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 14:57:35 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/24 17:49:50 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_toupper(int c)
{
	unsigned char	uc;

	if (c == EOF)
		return (c);
	uc = c;
	if (uc >= 'a' && uc <= 'z')
		return (uc & 0x5f);
	return (uc);
}
