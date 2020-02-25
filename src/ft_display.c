/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:52:06 by tamather          #+#    #+#             */
/*   Updated: 2020/02/25 12:01:28 by tamather         ###   ########.fr       */
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

int		zero(pf t, long digit)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (digit < 0)
		ft_putchar_fd('-', 1);
	if (t.flagO)
	{
		while (t.flagO > i++)
		{
			write(1, "0", 1);
			c++;
		}
	}
	return (c);
}

int		display_string(pf t, char *string)
{
	int		i;
	char	null[10];
	int		size;

	i = 0;
	size = 0;
	ft_strlcpy(null, "(null)", 7);
	if (string == NULL)
		string = null;
	if ((size_t)t.precision > ft_strlen(string))
		size = ft_strlen(string);
	else
		size = (t.p_on && ft_strlen(string) ? t.precision : ft_strlen(string));
	if (t.flagn)
	{
		ft_putstr_w_fd(string, size, 1);
		i = separator(t, size);
	}
	else
	{
		i = separator(t, size);
		ft_putstr_w_fd(string, size, 1);
	}
	i += size;
	return (i);
}

int		digits_print(pf *t, long digits, int base)
{
	int i;
	int size;

	i = 0;
	size = digit_size(digits, base) + (*t).flagO;
	if ((*t).flagn)
	{
		i += zero((*t), digits);
		if (!(digits == 0 && (*t).p_on && !(*t).precision))
			ft_putnbr_base_fd(digits, base, ((*t).format == 'X' ? 1 : 0), 1);
		i += separator((*t), size);
	}
	else
	{
		i += separator((*t), size);
		i += zero((*t), digits);
		if (!(digits == 0 && (*t).p_on && !(*t).precision))
			ft_putnbr_base_fd(digits, base, ((*t).format == 'X' ? 1 : 0), 1);
	}
	return (i);
}

int		display_digits(pf t, long digits)
{
	int		i;
	int		size;
	int		base;

	base = (t.format == 'x' || t.format == 'X' || t.format == 'p' ? 16 : 10);
	i = digit_size(digits, base);
	if (!t.width && (t.p_on))
	{
		t.width = t.flagO;
		t.flagO = t.precision;
	}
	if (t.precision < i && t.p_on)
		t.flagO = 0;
	else if (!t.O_on && !t.width)
		t.flagO = t.precision - i;
	else if (!t.width)
		t.flagO -= i;
	else if (t.precision)
		t.flagO = t.precision - i;
	if (digits == 0 && t.p_on && !t.precision )
	{
		t.width += (t.width ? 1 : 0);
		t.flagO += ((t.O_on && t.precision) ? 1 : 0);
		i--;
	}

	if (digits < 0 && t.precision + 1 > i)
		t.flagO++;
	size = digit_size(digits, base) + t.flagO;
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
	else if (t.format == 'd' || t.format == 'i')
		i = display_digits(t, va_arg(list, int));
	else if (t.format == 'u' || t.format == 'x' || t.format == 'X')
		i = display_digits(t, va_arg(list, unsigned int));
	else if (t.format == 'c')
		i = display_char(t, va_arg(list, int));
	else if (t.format == 'c')
		i = display_char(t, va_arg(list, int));
	else if (t.format == '%')
	{
		write(1, "%", 1);
		i++;
	}
	return (i);
}
