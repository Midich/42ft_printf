/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msowinsk <msowinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 13:29:53 by msowinsk          #+#    #+#             */
/*   Updated: 2026/06/27 16:15:15 by msowinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*map(t_list *lst, void *(*f)(void *))
{
	void	*new_content;

	new_content = f(lst->content);
	if (!new_content)
		return (0);
	return (ft_lstnew(new_content));
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new;
	t_list	*temp;

	if (!lst || !f || !del)
		return (0);
	temp = map(lst, f);
	if (!temp)
		return (0);
	node = temp;
	new = temp;
	lst = lst->next;
	while (lst)
	{
		temp = map(lst, f);
		if (!temp)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		node->next = temp;
		node = temp;
		lst = lst->next;
	}
	return (new);
}
