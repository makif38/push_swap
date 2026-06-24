/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 16:05:03 by akkaraka          #+#    #+#             */
/*   Updated: 2026/06/22 17:38:56 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printptr_hex(unsigned long nbr)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
		return (ft_printptr_hex(nbr / 16) + (ft_printptr_hex(nbr % 16)));
	return (ft_printchar(base[nbr]));
}

int	ft_printhex(unsigned int nbr, char format)
{
	int		len;
	char	*base;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		len += ft_printhex(nbr / 16, format);
		len += ft_printhex(nbr % 16, format);
	}
	else
		len += ft_printchar(base[nbr]);
	return (len);
}

int	ft_printptr(unsigned long nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (ft_printstr("(nil)"));
	len += ft_printstr("0x");
	len += ft_printptr_hex(nbr);
	return (len);
}
