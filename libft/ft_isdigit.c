/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 16:22:55 by akkaraka          #+#    #+#             */
/*   Updated: 2026/05/04 17:47:03 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// int main()
// {
//     char c;
//     c='5';
//     printf("\n numeric character is passed: %d", ft_isdigit(c));

//     c='+';
//     printf("\n non-numeric character is passed: %d", ft_isdigit(c));

//     return 0;
// }