/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:31:47 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/11 20:15:36 by akkaraka         ###   ########.fr       */
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
	if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX || ft_strlen(str) > 11)
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

static int	check_and_push(t_stack **a, char *str)
{
	int	value;

	if (!is_valid_number(str))
		return (0);
	value = ft_atoi(str);
	if (duplicate_check(*a, value))
		return (0);
	push_front(a, value);
	return (1);
}

static void	parse_split(t_stack **a, char *str)
{
	char	**split;
	int		j;

	split = ft_split(str, ' ');
	j = 0;
	while (split[j])
		j++;
	j--;
	while (j >= 0)
	{
		if (!check_and_push(a, split[j]))
		{
			free_stack(a);
			ft_printf("Error\n");
			exit(1);
		}
		j--;
	}
	j = 0;
	while (split[j])
		free(split[j++]);
	free(split);
}

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*a;
	int		i;

	a = NULL;
	i = argc - 1;
	while (i >= 0)
	{
		parse_split(&a, argv[i]);
		i--;
	}
	return (a);
}
