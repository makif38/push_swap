/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 22:16:34 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/12 01:32:36 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double n)
{
	int	integer;
	int	decimal;

	n = n * 100;
	integer = (int)n;
	decimal = (int)((n - integer) * 100 + 0.5);
	ft_putnbr_fd(integer, 2);
	write(2, ".", 1);
	if (decimal < 10)
		write(2, "0", 1);
	ft_putnbr_fd(decimal, 2);
	write (2, "%", 1);
}

static void	print_ops(t_data *data)
{
	ft_putstr_fd("sa: ", 2);
	ft_putnbr_fd(data->bench.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(data->bench.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(data->bench.ss, 2);
	ft_putstr_fd("\npa: ", 2);
	ft_putnbr_fd(data->bench.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(data->bench.pb, 2);
	ft_putstr_fd("\nra: ", 2);
	ft_putnbr_fd(data->bench.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(data->bench.rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(data->bench.rr, 2);
	ft_putstr_fd("\nrra: ", 2);
	ft_putnbr_fd(data->bench.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(data->bench.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(data->bench.rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_data *data)
{
	ft_putstr_fd("Disorder: ", 2);
	print_disorder(data->bench.disorder);
	ft_putstr_fd("\nStrategy: ", 2);
	if (data->bench.strategy)
		ft_putstr_fd(data->bench.strategy, 2);
	ft_putstr_fd(" | ", 2);
	if (data->bench.complexity)
		ft_putstr_fd(data->bench.complexity, 2);
	ft_putstr_fd("\nTotal operations: ", 2);
	ft_putnbr_fd(data->bench.total, 2);
	ft_putstr_fd("\n", 2);
	print_ops(data);
}
