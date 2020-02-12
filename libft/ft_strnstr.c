/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:33:48 by tamather          #+#    #+#             */
/*   Updated: 2019/10/28 23:55:32 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (i < n && *s1)
	{
		j = 0;
		while (s2[j] == s1[j] && s1[j] && s2[j])
			j++;
		if (s2[j] == '\0' && i + j < n + 1)
			return ((char*)s1);
		s1++;
		i++;
	}
	return (0);
}
