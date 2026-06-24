/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:45:41 by akkaraka          #+#    #+#             */
/*   Updated: 2026/05/05 22:48:48 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	if (!dest && !src)
		return (dest);
	d = ((unsigned char *)dest);
	s = ((const unsigned char *)src);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
