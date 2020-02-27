/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:29:52 by tamather          #+#    #+#             */
/*   Updated: 2020/02/27 03:42:46 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char	*pf_check_param(char *pos, va_list list, int *n)
{
	t_pf t;

	t = pf_parse_param(pos + 1, list);
	*n += pf_formater(t, list);
	return (t.pos + 1);
}

int		pf_print(char *arg, va_list list)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (*arg)
	{
		if (*arg == '%')
			arg = pf_check_param(arg, list, &n);
		else
			while (*arg != '%' && *arg)
			{
				write(1, arg, 1);
				n++;
				arg++;
			}
	}
	return (n);
}

int		ft_printf(const char *arg, ...)
{
	va_list	list;
	int		result;

	va_start(list, arg);
	result = pf_print((char *)arg, list);
	va_end(list);
	return (result);
}
