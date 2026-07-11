/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 20:24:32 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/12 01:25:19 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	run_sort(t_data *data, char *flag)
{
	if (ft_strncmp(flag, "--simple", 8) == 0)
	{
		data->bench.complexity = "O(n²)";
		selection_sort(data);
	}
	else if (ft_strncmp(flag, "--medium", 8) == 0)
	{
		data->bench.complexity = "O(n√n)";
		chunk_sort(data);
	}
	else if (ft_strncmp(flag, "--complex", 9) == 0)
	{
		data->bench.complexity = "O(n log n)";
		radix_sort(data);
	}
	else
	{
		data->bench.complexity = "O(n log n)";
		adaptive_sort(data);
	}
}

static int	get_first(int argc, char **argv, t_data *data, char **algo)
{
	int	first;

	first = 1;
	*algo = "--adaptive";
	if (argc < 2)
		return (-1);
	data->bench = (t_bench){0};
	data->b = NULL;
	if (ft_strncmp(argv[1], "--bench", 7) == 0)
	{
		data->bench.enabled = 1;
		first++;
	}
	if (first < argc
		&& (ft_strncmp(argv[first], "--simple", 8) == 0
			|| ft_strncmp(argv[first], "--medium", 8) == 0
			|| ft_strncmp(argv[first], "--complex", 9) == 0
			|| ft_strncmp(argv[first], "--adaptive", 10) == 0))
	{
		*algo = argv[first];
		first++;
	}
	return (first);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		first;
	char	*algo;
	// float	disorder;

	first = get_first(argc, argv, &data, &algo);
	if (first == -1)
		return (0);
	data.bench.strategy = algo;
	data.a = parse_input(argc - first, argv + first);
	data.bench.disorder = compute_disorder(data.a);
	run_sort(&data, algo);
	if (data.bench.enabled)
		print_bench(&data);
	free_stack(&data.a);
	free_stack(&data.b);
	return (0);
}
