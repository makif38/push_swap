/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:43:52 by akkaraka          #+#    #+#             */
/*   Updated: 2026/05/05 23:11:33 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	write (fd, &"0123456789"[n % 10], 1);
}

//*For example n = 123, we call ft_putnbr_fd(12),
//which calls ft_putnbr_fd(1), which stops recursing and writes 1.
//Then as the calls return they write 2, then 3 — left to right.*//
//*n % 10 gives the last digit as a number (0-9). 
//We use it as an index into the string "0123456789" to get the character,
//then take its address with & to pass to write.*//