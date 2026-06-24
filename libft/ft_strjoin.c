/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akkaraka <akkaraka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 00:58:40 by akkaraka          #+#    #+#             */
/*   Updated: 2026/06/22 14:35:40 by akkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*snew;
	int		i;
	int		j;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	i = 0;
	j = 0;
	snew = (char *) malloc((ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)
			* sizeof(char));
	if (!snew)
		return (NULL);
	while (s1[i])
		snew[j++] = s1[i++];
	i = 0;
	while (s2[i])
		snew[j++] = s2[i++];
	snew[j] = 0;
	return (snew);
}

//gcc ft_strjoin.c ft_strlen.c -o strjoin_test <--- BENUZTEN SONST 
//KANN MAN NICHT COMPILEN !!!