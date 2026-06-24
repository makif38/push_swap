/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:31:47 by akkaraka          #+#    #+#             */
/*   Updated: 2026/06/24 18:02:58 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	duplicate_check(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stack *parse_input(int argc, char **argv)
{
	t_stack	*a;
	int		value;
	int		i;

	a = NULL;
	i = argc - 1;
	while (i >= 1)
	{
		if (!is_valid_number(argv[i]))
		{
			free_stack(&a);
			ft_printf("Error\n");
			exit (1);
		}
		value = ft_atoi(argv[i]);
		if (duplicate_check(a, value))
		{
			free_stack(&a);
			ft_printf("Error\n");
			exit (1);
		}
		push_front(&a, value);
		i--;
	}
	return (a);
}