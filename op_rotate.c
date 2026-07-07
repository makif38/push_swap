/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:51:15 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/07 18:17:31 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_data *data)
{
	rotate(&data->a);
	data->bench.ra++;
	data->bench.total++;
	ft_printf("ra\n");
}

void	rb(t_data *data)
{
	rotate(&data->b);
	data->bench.rb++;
	data->bench.total++;
	ft_printf("rb\n");
}

void	rr(t_data *data)
{
	rotate(&data->a);
	rotate(&data->b);
	data->bench.rr++;
	data->bench.total++;
	ft_printf("rr\n");
}
