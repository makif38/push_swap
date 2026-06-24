/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:58:06 by akkaraka          #+#    #+#             */
/*   Updated: 2026/06/24 19:19:01 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
	{
		len += ft_printchar('-');
		len += ft_printchar('2');
		nbr = 147483648;
	}
	if (nbr < 0)
	{
		len += ft_printchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		len += ft_printnbr (nbr / 10);
		len += ft_printnbr (nbr % 10);
	}
	else
		len += ft_printchar (nbr + '0');
	return (len);
}

int	ft_printunsigned(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr >= 10)
	{
		len += ft_printunsigned (nbr / 10);
		len += ft_printunsigned (nbr % 10);
	}
	else
		len += ft_printchar (nbr + '0');
	return (len);
}
