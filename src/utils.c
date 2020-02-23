/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 02:56:50 by tamather          #+#    #+#             */
/*   Updated: 2020/02/23 19:38:08 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include <stdio.h>

void	ft_putstr_w_fd(char *s, int size, int fd)
{
    int i;

    i = 0;
	while (*s && i < size)
    {
		write(fd, s++, 1);
        i++;
    }
}

int		digit_size(long i, int base)
{
	int c;

	c = 0;
	while (i > base)
	{
		i /= base;
		c++;
	}
	//printf(".%d.", c + 1);
	return (c + 1);
}

void	ft_putnbr_base_fd(long int tmp, int base, int up_on, int fd)
{
	if (tmp < 0)
	{
		if (tmp < -2147483647)
		{
			tmp = tmp * -1;
			ft_putchar_fd('-', fd);
		}
		else
			tmp = tmp * -1;
	}
	if (tmp >= base)
	{
		ft_putnbr_base_fd(tmp / base, base, up_on, fd);
		if (tmp % base < 10)
			ft_putchar_fd((tmp % base) + '0', fd);
		else
			ft_putchar_fd((tmp % base) + (up_on ? 'A' : 'a') - 10, fd);
	}
	if (tmp < base)
	{
		if (tmp < 10)
			tmp += '0';
		else
			tmp+= (up_on ? 'A' : 'a') - 10;
		ft_putchar_fd(tmp, fd);
	}
}