/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 22:16:34 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/07 22:25:14 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench(t_data *data)
{
	ft_putstr_fd("=== BENCHMARK ===\n", 2);

	ft_putstr_fd("Strategy: ", 2);
	if (data->bench.strategy)
		ft_putstr_fd(data->bench.strategy, 2);
	else
		ft_putstr_fd("unknown", 2);
	ft_putstr_fd("\n", 2);

	ft_putstr_fd("Complexity: ", 2);
	if (data->bench.complexity)
		ft_putstr_fd(data->bench.complexity, 2);
	else
		ft_putstr_fd("unknown", 2);
	ft_putstr_fd("\n", 2);

	ft_putstr_fd("Operations: ", 2);
	ft_putnbr_fd(data->bench.total, 2);
	ft_putstr_fd("\n", 2);

	ft_putstr_fd("sa: ", 2);
	ft_putnbr_fd(data->bench.sa, 2);
	ft_putstr_fd("\npb: ", 2);
	ft_putnbr_fd(data->bench.pb, 2);
	ft_putstr_fd("\npa: ", 2);
	ft_putnbr_fd(data->bench.pa, 2);
	ft_putstr_fd("\nra: ", 2);
	ft_putnbr_fd(data->bench.ra, 2);
	ft_putstr_fd("\nrb: ", 2);
	ft_putnbr_fd(data->bench.rb, 2);
	ft_putstr_fd("\nrr: ", 2);
	ft_putnbr_fd(data->bench.rr, 2);
	ft_putstr_fd("\nrra: ", 2);
	ft_putnbr_fd(data->bench.rra, 2);
	ft_putstr_fd("\nrrb: ", 2);
	ft_putnbr_fd(data->bench.rrb, 2);
	ft_putstr_fd("\nrrr: ", 2);
	ft_putnbr_fd(data->bench.rrr, 2);
	ft_putstr_fd("\n", 2);
}
