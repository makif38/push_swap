/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:50:32 by akkaraka          #+#    #+#             */
/*   Updated: 2026/06/25 20:50:19 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int min_position(t_stack *stack)
{
	t_stack	*current;
	int		min_value;
	int		min_pos;
	int		current_pos;

	current = stack;
	min_value = stack->value;
	min_pos = 0;
	current_pos = 0;
	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = current_pos;
		}
		current_pos++;
		current = current->next;
	}
	return (min_pos);
}

