/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 17:14:13 by akkaraka          #+#    #+#             */
/*   Updated: 2026/06/22 17:18:31 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#  ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <string.h>

typedef struct s_stack 
{
	int				value;
	struct s_stack	*next;
} t_stack;

#endif