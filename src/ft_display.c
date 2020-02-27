/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:52:06 by tamather          #+#    #+#             */
/*   Updated: 2020/02/27 03:42:50 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../libft/libft.h"

int		display_string(t_pf t, char *string)
{
	int		i;
	char	null[10];
	int		size;

	i = 0;
	size = 0;
	ft_strlcpy(null, "(null)", 7);
	if (string == NULL)
		string = null;
	if ((size_t)t.pre > ft_strlen(string))
		size = ft_strlen(string);
	else
		size = (t.p_on && ft_strlen(string) ? t.pre : ft_strlen(string));
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

int		digits_print(t_pf *t, long digits, int base)
{
	int i;
	int size;

	i = 0;
	if (digits < 0 && (*t).pre + 1 > digit_size(digits, base))
		(*t).flago++;
	(*t).width -= (i = (*t).format == 'p' ? 2 : 0);
	size = digit_size(digits, base) + (*t).flago;
	if ((*t).flagn)
	{
		i += zero((*t), digits);
		(*t).format == 'p' ? write(1, "0x", 2) : 0;
		if (!(digits == 0 && (*t).p_on && !(*t).pre) && (*t).format != '%')
			ft_putnbr_base_fd(digits, base, ((*t).format == 'X' ? 1 : 0), 1);
		i += separator((*t), size);
	}
	else
	{
		i += separator((*t), size);
		i += zero((*t), digits);
		(*t).format == 'p' ? write(1, "0x", 2) : 0;
		if (!(digits == 0 && (*t).p_on && !(*t).pre) && (*t).format != '%')
			ft_putnbr_base_fd(digits, base, ((*t).format == 'X' ? 1 : 0), 1);
	}
	return (i);
}

int		display_digits(t_pf t, long digits)
{
	int		i;
	int		base;

	base = (t.format == 'x' || t.format == 'X' || t.format == 'p' ? 16 : 10);
	i = digit_size(digits, base);
	if (!t.width && (t.p_on))
	{
		t.width = t.flago;
		t.flago = t.pre;
	}
	if (t.pre < i && t.p_on)
		t.flago = 0;
	else if (!t.o_on && !t.width)
		t.flago = t.pre - i;
	else if (!t.width)
		t.flago -= i;
	else if (t.pre)
		t.flago = t.pre - i;
	if (digits == 0 && t.p_on && !t.pre)
	{
		t.width += (t.width ? 1 : 0);
		t.flago += ((t.o_on && t.pre) ? 1 : 0);
		i--;
	}
	return (i += digits_print(&t, digits, base));
}

int		display_char(t_pf t, int c)
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

int		pf_formater(t_pf t, va_list list)
{
	int i;

	i = 0;
	if (t.format == 's')
		i = display_string(t, va_arg(list, char *));
	else if (t.format == 'd' || t.format == 'i')
		i = display_digits(t, va_arg(list, int));
	else if (t.format == 'u' || t.format == 'x' || t.format == 'X')
		i = display_digits(t, va_arg(list, unsigned int));
	else if (t.format == 'p')
		i = display_digits(t, va_arg(list, long));
	else if (t.format == 'c')
		i = display_char(t, va_arg(list, int));
	else if (t.format == '%')
	{
		if (t.flagn)
			write(1, "%", 1);
		i = display_digits(t, 0);
		if (!t.flagn)
			write(1, "%", 1);
	}
	return (i);
}
