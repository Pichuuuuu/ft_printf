/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 11:03:10 by tamather          #+#    #+#             */
/*   Updated: 2019/10/27 01:42:50 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_int_size(int n)
{
	int c;

	c = 0;
	while (((n < 0) ? n <= -10 : n >= 10))
	{
		n /= 10;
		c++;
	}
	return (++c);
}

char			*ft_itoa(int n)
{
	char	*a;
	int		i;

	if (!(a = malloc(sizeof(char) * (count_int_size(n) + ((n < 0) ? 2 : 1)))))
		return (0);
	i = count_int_size(n) + ((n < 0) ? 0 : -1);
	a[i + 1] = '\0';
	while (((n < 0) ? n <= -10 : n >= 10))
	{
		a[i] = ((n % 10) * ((n < 0) ? -1 : 1)) + '0';
		n /= 10;
		i--;
	}
	a[i] = (n * ((n < 0) ? -1 : 1)) + '0';
	if (n < 0)
		a[--i] = '-';
	return (a);
}
