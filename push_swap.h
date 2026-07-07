/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:14:13 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/07 22:18:15 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}	t_stack;

typedef struct s_bench
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;

	int		total;
	int		enabled;

	double	disorder;
	char	*strategy;
	char	*complexity;
}	t_bench;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
}	t_data;

void	push_front(t_stack **stack, int value);
void	print_stack(t_stack *stack, char *name);
void	free_stack(t_stack **stack);
void	pa(t_data *data);
void	pb(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
t_stack	*new_node(int value);
int	stack_size(t_stack *stack);
t_stack	*parse_input(int argc, char **argv);
double	compute_disorder(t_stack *stack);
void	selection_sort(t_data *data);
void	assign_rank(t_stack *stack);
void	chunk_sort(t_data *data);
void	radix_sort(t_data *data);
void	adaptive_sort(t_data *data);
void	print_bench(t_data *data);

#endif