/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 04:49:16 by tamather          #+#    #+#             */
/*   Updated: 2019/10/26 23:11:27 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*srcc;
	char	*destt;
	size_t	i;

	srcc = (char*)src;
	destt = (char*)dest;
	i = 0;
	while (n > i)
	{
		destt[i] = srcc[i];
		i++;
	}
	return (dest);
}
