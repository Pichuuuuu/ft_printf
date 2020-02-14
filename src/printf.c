/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:29:52 by tamather          #+#    #+#             */
/*   Updated: 2020/02/14 08:51:29 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int 	arg_count(const char *arg)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while(arg[i])
	{
		if (arg[i] == '%' && arg[i + 1] != '%')
			if (arg[i + 1] == 'c' || arg[i + 1] == 's' || arg[i + 1] == 'p'|| arg[i + 1] == 'i' 
				|| arg[i + 1] == 'u' || arg[i + 1] == 'x' || arg[i + 1] == 'X')
				c++;
		i++;
	}
	return(c);
}

char	*pf_check_param(char *pos, va_list list)
{
	(void)list;
	pf t;
	
	t = pf_parse_param(pos + 1);
	write(1, &t.format, 1);
	
	return t.pos + 1;
}

int		pf_print(char *arg, va_list list)
{
	int i;

	i = 0;
	while (*arg)
	{
		if (*arg == '%')
			arg = pf_check_param(arg , list);
		else
			while(*arg != '%' && *arg)
			{
				write(1, arg, 1);
				arg++;
			}
	}
	return 0;
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
