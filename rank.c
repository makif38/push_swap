/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 03:32:53 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/06 03:35:43 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_rank(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;
	int		rank;

	i = stack;
	while (i)
	{
		rank = 0;
		j = stack;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		i->rank = rank;
		i = i->next;
	}
}