/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:49:50 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/12 00:50:56 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	t_stack	*tmp;

	if (!data->b)
		return ;
	tmp = data->b;
	data->b = data->b->next;
	tmp->next = data->a;
	data->a = tmp;
	data->bench.pa++;
	data->bench.total++;
	ft_printf("pa\n");
}

void	pb(t_data *data)
{
	t_stack	*tmp;

	if (!data)
		return ;
	tmp = data->a;
	data->a = data->a->next;
	tmp->next = data->b;
	data->b = tmp;
	data->bench.pb++;
	data->bench.total++;
	ft_printf("pb\n");
}
