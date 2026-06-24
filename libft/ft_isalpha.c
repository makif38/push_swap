/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:57:20 by akkaraka          #+#    #+#             */
/*   Updated: 2026/05/04 17:46:37 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// int main()
// {
//     char c;
//     c = 'Q';
//     printf("\n uppercase alphabet passed: %d", ft_isalpha(c));

//     c = 'q';
//     printf("\n lowercase alphabet passed: %d", ft_isalpha(c));

//     c ='+';
//     printf("\n non-alphabetic character passed: %d", ft_isalpha(c));

//     return 0;
// }