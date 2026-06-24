/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:50:39 by akkaraka          #+#    #+#             */
/*   Updated: 2026/05/04 17:47:53 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof (t_list));
	if (!node)
		return (NULL);
	node -> next = NULL;
	node -> content = content;
	return (node);
}

// int main(void)
// {
// 	t_list *node;

// 	node = ft_lstnew("Hello");

// 	if (node)
// 		printf("%s\n", (char *)node->content);

// 	return (0);
// }