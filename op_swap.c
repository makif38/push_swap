/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:26:39 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/07 18:20:34 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_data *data)
{
	swap(&data->a);
	data->bench.sa++;
	data->bench.total++;
	ft_printf("sa\n");
}

void	sb(t_data *data)
{
	swap(&data->b);
	data->bench.sb++;
	data->bench.total++;
	ft_printf("sb\n");
}

void	ss(t_data *data)
{
	swap(&data->a);
	swap(&data->b);
	data->bench.ss++;
	data->bench.total++;
	ft_printf("ss\n");
}
