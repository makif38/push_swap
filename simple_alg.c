/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 17:50:32 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/07 18:24:50 by akkaraka         ###   ########.fr       */
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

void	rotate_top(t_data *data, int position, int size)
{
	if (position <= size / 2)
	{
		while (position--)
			ra(data);
	}
	else
	{
		position = size - position;
		while (position--)
			rra(data);
	}
}

void	selection_sort(t_data *data)
{
	int	size;
	int min_pos;

	size = stack_size(data->a);
	while (data->a)
	{
		min_pos = min_position(data->a);
		rotate_top(data, min_pos, size);
		pb(data);
		size--;
	}
	while (data->b)
		pa(data);
}
