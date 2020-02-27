/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 02:56:50 by tamather          #+#    #+#             */
/*   Updated: 2020/02/27 03:42:43 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/printf.h"
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
	if (i < 0)
	{
		i *= -1;
		c++;
	}
	while (i >= base)
	{
		i /= base;
		c++;
	}
	return (c + 1);
}

void	ft_putnbr_base_fd(long tmp, int base, int up_on, int fd)
{
	if (tmp < 0)
		tmp = tmp * -1;
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
			tmp += (up_on ? 'A' : 'a') - 10;
		ft_putchar_fd(tmp, fd);
	}
}

int		separator(t_pf t, int size)
{
	int c;

	c = 0;
	if (t.width)
	{
		t.width = (t.flagp ? t.width - 1 : t.width);
		while (t.width > size++)
		{
			write(1, " ", 1);
			c++;
		}
		if (t.flagp)
		{
			write(1, "+", 1);
			c++;
		}
	}
	return (c);
}

int		zero(t_pf t, long digit)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (digit < 0)
		ft_putchar_fd('-', 1);
	if (t.flago)
	{
		while (t.flago > i++)
		{
			write(1, "0", 1);
			c++;
		}
	}
	return (c);
}
