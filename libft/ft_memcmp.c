/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:18:50 by tamather          #+#    #+#             */
/*   Updated: 2019/10/26 23:11:21 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*cs1;
	char	*cs2;

	cs1 = (char*)s1;
	cs2 = (char*)s2;
	i = 0;
	while (i < n)
	{
		if (cs2[i] != cs1[i])
			return ((unsigned char)cs1[i] - (unsigned char)cs2[i]);
		i++;
	}
	return (0);
}
