/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reversed_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:09:23 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/07 18:15:25 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_last = *stack;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_data *data)
{
	reverse_rotate(&data->a);
	data->bench.rra++;
	data->bench.total++;
	ft_printf("rra\n");
}

void	rrb(t_data *data)
{
	reverse_rotate (&data->b);
	data->bench.rrb++;
	data->bench.total++;
	ft_printf("rrb\n");
}

void	rrr(t_data *data)
{
	reverse_rotate(&data->a);
	reverse_rotate(&data->b);
	data->bench.rrr++;
	data->bench.total++;
	ft_printf("rrr\n");
}
