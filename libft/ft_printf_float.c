/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 19:18:36 by akkaraka          #+#    #+#             */
/*   Updated: 2026/06/24 19:39:19 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printfloat(double n)
{
	int		count;
	int		integer;
	int		decimal;

	count = 0;
	integer = (int)n;
	decimal = (int)((n - integer) * 1000000 + 0.5);
	count += ft_printnbr(integer);
	count += ft_printchar('.');
	if (decimal < 100000)
		count += ft_printchar('0');
	if (decimal < 10000)
		count += ft_printchar('0');
	if (decimal < 1000)
		count += ft_printchar('0');
	if (decimal < 100)
		count += ft_printchar('0');
	if (decimal < 10)
		count += ft_printchar('0');
	count += ft_printnbr(decimal);
	return (count);
}
