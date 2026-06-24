/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 16:19:13 by akkaraka          #+#    #+#             */
/*   Updated: 2026/06/24 19:15:59 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	checknext(char c, va_list args)
{
	if (c == '%')
		return (ft_printchar('%'));
	else if (c == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (c == 'f')
		return (ft_printfloat(va_arg(args, double)));
	else if (c == 'p')
		return (ft_printptr(va_arg(args, unsigned long)));
	else if (c == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (c == 'i' || c == 'd')
		return (ft_printnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printunsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_printhex(va_arg(args, unsigned int), 'x'));
	else if (c == 'X')
		return (ft_printhex(va_arg(args, unsigned int), 'X'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start (args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += checknext(str[i], args);
		}
		else
			count += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
