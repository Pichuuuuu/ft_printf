/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:54:50 by tamather          #+#    #+#             */
/*   Updated: 2019/10/28 23:55:31 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *p;

	p = 0;
	while (*s)
	{
		if (*s == c)
			p = (char*)s;
		s++;
	}
	if (p)
		return (p);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
