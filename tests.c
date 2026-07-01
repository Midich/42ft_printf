/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 14:39:35 by msowinsk          #+#    #+#             */
/*   Updated: 2026/07/01 14:44:03 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *c[] = {0, "", "hello", "hello world", "\n\b\t\\\r"}
	for (int i = 0; i < sizeof(c)/sizeof(c[0]); i++)
	{
		printf(c[i]);
		ft_printf(c[i]);
	}
}
