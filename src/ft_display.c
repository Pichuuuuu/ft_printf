/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:52:06 by tamather          #+#    #+#             */
/*   Updated: 2020/02/17 16:20:26 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../libft/libft.h"

int		display_string(pf t, char *string)
{
	t.format = 0;
	ft_putstr_fd(string, 1);
	return (0);
}

int		display_digits(pf t, int digits)
{
	t.format = 0;
	digits = 0;
	return (0);
}

void	separator(pf t)
{
	int i;

	i = 1;
	if (atoi(t.width))
	{
		while (atoi(t.width) > i++)
			write(1, " ", 1);
	}
	else if (t.precision)
	{
		while (t.precision > i++)
			write(1, " ", 1);
	}
}

int		display_char(pf t, int c)
{
	if (t.flag[0] == '-')
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
	if (t.precision)
		t.precision = va_arg(list, int);
	if (t.format == 's')
		display_string(t, va_arg(list, char *));
	else if (t.format == 'd' || t.format == 'i' ||
		t.format == 'x' || t.format == 'X')
		display_digits(t, va_arg(list, int));
	else if (t.format == 'c')
		display_char(t, va_arg(list, int));
	return (0);
}
