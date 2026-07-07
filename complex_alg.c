/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:30:11 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/07 18:34:52 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_next_bits(int n)
{
	int	bits;
	int	max;

	max = n - 1;
	bits = 0;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

static void	radix_round(t_data *data, int n, int bit)
{
	int	j;

	j = 0;
	while (j < n)
	{
		if (((data->a)->rank >> bit) & 1)
			ra(data);
		else
			pb(data);
		j++;
	}
	while (data->b)
		pa(data);
}

void	radix_sort(t_data *data)
{
	int	n;
	int	max_bits;
	int	i;

	n = stack_size(data->a);
	assign_rank(data->a);
	max_bits = get_next_bits(n);
	i = 0;
	while (i < max_bits)
	{
		radix_round(data, n, i);
		i++;
	}
}
