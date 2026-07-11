/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:29:40 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/12 01:07:36 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_pos(t_data *data, int pos, int size, int is_a)
{
	if (pos <= size / 2)
	{
		while (pos--)
		{
			if (is_a)
				ra(data);
			else
				rb(data);
		}
	}
	else
	{
		pos = size - pos;
		while (pos--)
		{
			if (is_a)
				rra(data);
			else
				rrb(data);
		}
	}
}

static int	find_chunk(t_stack **a, int pushed, int chunk_max, int *pos)
{
	t_stack	*cur;

	cur = *a;
	*pos = 0;
	while (cur && !(cur->rank >= pushed && cur->rank < chunk_max))
	{
		cur = cur->next;
		(*pos)++;
	}
	return (cur != NULL);
}

static void	push_b(t_data *data, int n, int chunk_size)
{
	int	pushed;
	int	pos;
	int	i;

	pushed = 0;
	i = 0;
	while (i < n)
	{
		if (!find_chunk(&data->a, pushed, pushed + chunk_size, &pos))
		{
			pushed += chunk_size;
			continue ;
		}
		rotate_to_pos(data, pos, stack_size(data->a), 1);
		pb(data);
		i++;
	}
}

static void	push_a(t_data *data)
{
	t_stack	*cur;
	int		pos;
	int		max_rank;
	int		max_pos;

	while (data->b)
	{
		cur = data->b;
		max_rank = cur->rank;
		pos = 0;
		max_pos = 0;
		while (cur)
		{
			if (cur->rank > max_rank)
			{
				max_rank = cur->rank;
				max_pos = pos;
			}
			pos++;
			cur = cur->next;
		}
		rotate_to_pos(data, max_pos, stack_size(data->b), 0);
		pa(data);
	}
}

void	chunk_sort(t_data *data)
{
	int		n;
	int		chunk_size;
	float	disorder;

	n = stack_size(data->a);
	disorder = compute_disorder(data->a);
	if (n <= 10)
		chunk_size = 3;
	else if (n <= 50)
		chunk_size = 7;
	else if (n <= 100)
	{
		if (disorder < 0.5)
			chunk_size = 18;
		else
			chunk_size = 40;
	}
	else if (n <= 500)
		chunk_size = 50;
	else
		chunk_size = 150;
	assign_rank(data->a);
	push_b(data, n, chunk_size);
	push_a(data);
}
