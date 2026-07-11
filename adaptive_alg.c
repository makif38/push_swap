/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 19:30:50 by akkaraka          #+#    #+#             */
/*   Updated: 2026/07/12 01:07:44 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_data *data)
{
	float	disorder;

	disorder = compute_disorder(data->a);
	if (disorder < 0.2)
		selection_sort(data);
	else if (disorder < 0.5)
		chunk_sort(data);
	else
		radix_sort(data);
}
