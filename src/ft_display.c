/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:52:06 by tamather          #+#    #+#             */
/*   Updated: 2020/02/20 03:32:29 by tamather         ###   ########.fr       */
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
		while (t.width > size++)
		{
			write(1, " ", 1);
			c++;
		}
	}
	return (c);
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

int		display_digits(pf t, int digits)
{
	char *r;

	r = ft_itoa(digits);
	printf("%d", (int)ft_strlen(r));
	display_string(t, r);
	free(r);
	return (0);
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
	else if (t.format == 'd' || t.format == 'i' ||
		t.format == 'x' || t.format == 'X')
		i = display_digits(t, va_arg(list, int));
	else if (t.format == 'c')
		i = display_char(t, va_arg(list, int));

	return (i);
}
