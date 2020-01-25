/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:29:52 by tamather          #+#    #+#             */
/*   Updated: 2020/01/16 15:04:58 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int arg_count(const char *arg)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while(arg[i])
	{
		if (arg[i] == '%')
			c++;
		i++;
	}
	return(c);
}

int		ft_printf(const char *arg, ...)
{
	va_list	list;
	int		result;
	printf("%d", arg_count(arg));
	va_start(list, arg_count(arg));
	
	va_end(list);
	return (result);
}

int main(int argc, char const *argv[])
{
	ft_printf(argv[1]);
	return 0;
}
