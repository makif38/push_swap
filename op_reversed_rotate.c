/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reversed_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:09:23 by akkaraka          #+#    #+#             */
/*   Updated: 2026/06/23 14:58:51 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last;

	last = *stack;
	while (second_last->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rb(t_stack **b)
{
	reverse_rotate (b);
	ft_printf("rrb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
