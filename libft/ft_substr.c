/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:41:15 by tamather          #+#    #+#             */
/*   Updated: 2019/11/06 08:22:46 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*out;

	i = 0;
	if (!s)
		return (0);
	if (!(out = ft_calloc(sizeof(char), len + 1)))
		return (0);
	if (start <= ft_strlen((char*)s))
	{
		while (s[i + start] && i < (int)len)
		{
			out[i] = s[i + start];
			i++;
		}
	}
	out[i] = '\0';
	return (out);
}
