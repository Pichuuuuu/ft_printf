/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 22:43:19 by tamather          #+#    #+#             */
/*   Updated: 2019/10/28 23:55:39 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *out;

	if (!(out = malloc(sizeof(char) * (ft_strlen((char*)s1)
		+ ft_strlen((char*)s2) + 1))))
		return (0);
	ft_strlcpy(out, s1, ft_strlen((char*)s1) + 1);
	ft_strlcat(out, s2, ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1);
	return (out);
}
