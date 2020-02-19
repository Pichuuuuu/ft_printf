/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:52:06 by tamather          #+#    #+#             */
/*   Updated: 2020/02/19 06:01:47 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../libft/libft.h"

void	separator(pf t)
{
	int i;

	i = 1;
	if (t.width)
		while (t.width > i++)
			write(1, " ", 1);
	else if (t.precision[0])
		while (t.precision[0] > i++)
			write(1, " ", 1);
}

int		display_string(pf t, char *string)
{
	if (t.width > 0)
	{
		if ((size_t)t.size > ft_strlen(string))
			t.width -= ft_strlen(string) - 1;
		else
			t.width -= (t.size > 0 ? t.size : 0) - 1;
	}
	if (t.precision[0])
	{
		if ((size_t)t.size > ft_strlen(string))
			t.precision[0] -= ft_strlen(string) - 1;
		else
			t.precision[0] -= (t.size > 0 ? t.size : 0) - 1;
	}
	if (t.flagn)
	{
		ft_putstr_w_fd(string, (t.size ? t.size : ft_strlen(string)), 1);
		separator(t);
	}
	else
	{
		separator(t);
		ft_putstr_w_fd(string, (t.size ? t.size : ft_strlen(string)), 1);
	}
	return (0);
}

int		display_digits(pf t, int digits)
{
	t.format = 0;
	digits = 0;
	return (0);
}

int		display_char(pf t, int c)
{
	if (t.flagn)
	{
		write(1, &c, 1);
		separator(t);
	}
	else
	{
		separator(t);
		write(1, &c, 1);
	}
	return (0);
}

int		pf_formater(pf t, va_list list)
{
	//printf("size = %d\n", t.size);
	//printf("width = %d\n", t.width);
	//printf("precision = %d\n", t.precision);
	if (t.format == 's')
		display_string(t, va_arg(list, char *));
	else if (t.format == 'd' || t.format == 'i' ||
		t.format == 'x' || t.format == 'X')
		display_digits(t, va_arg(list, int));
	else if (t.format == 'c')
		display_char(t, va_arg(list, int));
	else if (t.format == '%')
		write(1, "%", 1);
	return (0);
}
