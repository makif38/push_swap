#include "push_swap.h"
#include "libft/libft.h"
#include "stdio.h"

#include "push_swap.h"

static void	run_sort(t_data *data, char *flag)
{
	if (ft_strncmp(flag, "simple", 6) == 0)
	{
		data->bench.complexity = "O(n²)";
		selection_sort(data);
	}
	else if (ft_strncmp(flag, "chunk", 5) == 0)
	{
		data->bench.complexity = "O(n√n)";
		chunk_sort(data);
	}
	else if (ft_strncmp(flag, "radix", 5) == 0)
	{
		data->bench.complexity = "O(n*k)";
		radix_sort(data);
	}
	else
	{
		data->bench.complexity = "O(n log n)";
		adaptive_sort(data);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;
	int		first;
	char	*algo;

	first = 1;
	if (argc < 2)
		return (0);
	i = 1;
	data.bench = (t_bench){0};
	data.b = NULL;
	if (ft_strncmp(argv[1], "--bench", 7) == 0)
	{
		data.bench.enabled = 1;
		first++;
	}
	algo = "adaptive";
	if (first < argc &&
		(ft_strncmp(argv[first], "simple", 6) == 0
		|| ft_strncmp(argv[first], "chunk", 5) == 0
		|| ft_strncmp(argv[first], "radix", 5) == 0
		|| ft_strncmp(argv[first], "adaptive", 8) == 0))
		{
			algo = argv[first];
			first++;
		}
	data.bench.strategy = algo;
	data.a = parse_input(argc - first + 1, argv + first - 1);
	run_sort(&data, algo);
	if (data.bench.enabled)
		print_bench(&data);
	free_stack(&data.a);
	free_stack(&data.b);
	return (0);
}
