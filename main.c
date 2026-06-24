#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	double	disorder;

	if (argc < 2)
		return (0);
	a = parse_input(argc, argv);
	b = NULL;
	disorder = compute_disorder(a);
	ft_printf("Disorder: %f\n", disorder);
	// ft_printf kann kein %f - einfach so testen:
	print_stack(a, "a");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
