/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:42:29 by akkaraka          #+#    #+#             */
/*   Updated: 2026/05/05 23:24:31 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*src;

	i = 0;
	src = ((const unsigned char *)s);
	while (i < n)
	{
		if (src[i] == (unsigned char) c)
			return ((unsigned char *)src + i);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// #include "libft.h"

// int main(void)
// {
//     char str[] = "Hello World";

//     printf("Test 1: %s\n", (char *)memchr(str, '\0', strlen(str)));
//     printf("Test 2: %s\n", (char *)memchr(str, 'W', strlen(str)));

//     if (memchr(str, 'x', strlen(str)) == NULL)
//         printf("Test 3: NULL OK\n");

//     return 0;
// }