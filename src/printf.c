/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:29:52 by tamather          #+#    #+#             */
/*   Updated: 2020/02/12 08:50:19 by tamather         ###   ########.fr       */
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

int		pf_check_param(char *pos, va_list list)
{
	(void)list;
	printf("%s\n", pos);
	pf_parse_param(pos);
	return 0;
}

int		pf_print(const char *arg, va_list list)
{
	int i;

	i = 0;
	list = 0;
	if(list)
		write(1, "q", 1);
	while (arg[i])
	{
		if (arg[i] == '%')
			i += pf_check_param((char *)arg + i , list);
		else
			while(arg[i] != '%' && arg[i])
				i++;
	}
	return 0;
}

int		ft_printf(const char *arg, ...)
{
	va_list	list;
	int		result;

	va_start(list, arg);
	result = pf_print(arg, list);
	va_end(list);
	return (result);
}
