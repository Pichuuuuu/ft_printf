/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:29:52 by tamather          #+#    #+#             */
/*   Updated: 2020/01/31 05:28:24 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

int		pf_check_param()
{
	
}

int		pf_print(const char *arg, va_list list)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (arg[i])
	{
		if (arg[i] == '%')
		{
			
			i++;
		}
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

int main(int argc, char const *argv[])
{
	ft_printf(argv[1]);
	return 0;
}
