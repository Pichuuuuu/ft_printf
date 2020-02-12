/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 06:10:38 by tamather          #+#    #+#             */
/*   Updated: 2019/10/26 23:10:59 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*srcc;
	char	*destt;
	size_t	i;

	srcc = (char*)src;
	destt = (char*)dest;
	i = 0;
	while (i < n)
	{
		destt[i] = srcc[i];
		if ((unsigned char)srcc[i] == (unsigned char)c)
			return (&destt[i + 1]);
		i++;
	}
	return (0);
}
