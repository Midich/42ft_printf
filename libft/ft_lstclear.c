/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:22:03 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/23 14:39:42 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		last = *lst;
		*lst = (*lst)->next;
		del(last->content);
		free(last);
	}
	*lst = 0;
}
