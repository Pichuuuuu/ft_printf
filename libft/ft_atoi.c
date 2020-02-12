/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 23:29:39 by tamather          #+#    #+#             */
/*   Updated: 2019/10/27 01:40:55 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int in;
	int c;

	in = 0;
	c = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (*str == '-')
	{
		c++;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str <= '9' && *str >= '0')
	{
		in = in * 10;
		in = (in + *str - '0');
		str++;
	}
	if (c)
		in = -1 * in;
	return (in);
}
