/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:34:21 by tamather          #+#    #+#             */
/*   Updated: 2019/11/01 01:14:33 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strcpy(char *dest, char *src)
{
	int n;

	n = 0;
	while (src[n])
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (dest);
}

char			*ft_strdup(const char *src)
{
	char *cpy;

	if (!(cpy = malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (0);
	return (ft_strcpy(cpy, (char *)src));
}
