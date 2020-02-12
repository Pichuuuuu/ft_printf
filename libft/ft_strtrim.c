/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:29:24 by tamather          #+#    #+#             */
/*   Updated: 2019/10/28 23:55:28 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_charset(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (c);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen((char*)s1);
	while (is_charset(s1[i], (char*)set))
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	while ((len - i) && is_charset(s1[len - 1], (char*)set))
		len--;
	return (ft_substr(s1, i, len - i));
}
