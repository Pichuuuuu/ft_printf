/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:52:06 by tamather          #+#    #+#             */
/*   Updated: 2020/02/22 17:40:59 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../libft/libft.h"

int		separator(pf t, int size)
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

void		zero(pf t)
{
	int i;

	i = 0;
	if (t.flagO)
	{
		while (t.flagO > i++)
			write(1, "0", 1);
	}
}

int		display_string(pf t, char *string)
{
	int		i;
	char	null[10];

	i = 0;
	ft_strlcpy(null, "(null)", 7);
	if (string == NULL)
		string = null;
	if (t.flagn)
	{
		ft_putstr_w_fd(string, (t.p_on ? t.precision : ft_strlen(string)), 1);
		i = separator(t, (t.p_on ? t.precision : ft_strlen(string)));
	}
	else
	{
		i = separator(t, (t.p_on ? t.precision : ft_strlen(string)));
		ft_putstr_w_fd(string, (t.p_on ? t.precision : ft_strlen(string)), 1);
	}
	i += t.p_on ? t.precision : ft_strlen(string);
	return (i);
}

int		display_digits(pf t, long digits)
{
	int		i;
	int		size;
	int		base;

	base = (t.format == 'x' || t.format == 'X' ? 16 : 10);
	if (!t.width && t.flagO)
	{
		t.width = t.flagO;
		t.flagO = t.precision - digit_size(digits, base);
	}
	else
	{
		t.flagO = (t.flagO ? t.flagO : t.precision);
		if (!t.precision && !t.p_on && !t.flagO)
			t.flagO = 0;
		else
			t.flagO -= t.precision || !t.p_on ? digit_size(digits, base) : t.flagO;
	}
	size = digit_size(digits, base) + t.flagO;
	i = size;
	if (t.flagn)
	{
		zero(t);
		ft_putnbr_base_fd(digits, base, (t.format == 'X' ? 1 : 0), 1);
		i += separator(t, size);
	}
	else
	{
		i += separator(t, size);
		zero(t);
		ft_putnbr_base_fd(digits, base, (t.format == 'X' ? 1 : 0), 1);
	}
	return (i);
}

int		display_char(pf t, int c)
{
	int i;

	if (t.flagn)
	{
		write(1, &c, 1);
		i = separator(t, 1);
	}
	else
	{
		i = separator(t, 1);
		write(1, &c, 1);
	}
	return (i + 1);
}

int		pf_formater(pf t, va_list list)
{
	int i;

	i = 0;
	if (t.format == 's')
		i = display_string(t, va_arg(list, char *));
	else if (t.format == 'd' || t.format == 'i' || t.format == 'u' ||
		t.format == 'x' || t.format == 'X')
		i = display_digits(t, va_arg(list, int));
	else if (t.format == 'c')
		i = display_char(t, va_arg(list, int));
	else if (t.format == '%')
	{
		write(1, "%", 1);
		i++;
	}
	return (i);
}
