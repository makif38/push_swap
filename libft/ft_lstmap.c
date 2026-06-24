/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 17:38:43 by akkaraka          #+#    #+#             */
/*   Updated: 2026/04/30 20:08:42 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;
	void	*ncontent;

	newlst = NULL;
	while (lst)
	{
		ncontent = f(lst ->content);
		if (!ncontent)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		node = ft_lstnew(ncontent);
		if (!node)
		{
			del(ncontent);
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, node);
		lst = lst ->next;
	}
	return (newlst);
}
