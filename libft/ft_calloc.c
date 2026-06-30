/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 18:05:04 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/24 18:12:23 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	to_allocate;

	if (!n || !size)
	{
		n = 1;
		size = 1;
	}
	to_allocate = n * size;
	if (to_allocate / n != size)
		return (0);
	ptr = malloc(to_allocate);
	if (ptr)
		ft_bzero(ptr, to_allocate);
	return (ptr);
}
