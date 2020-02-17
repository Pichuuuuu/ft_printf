/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:52:06 by tamather          #+#    #+#             */
/*   Updated: 2020/02/16 16:14:26 by tamather         ###   ########.fr       */
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
}

int		pf_formater(pf t, va_list list)
{
	if (t.format == 's')
		display_string(t, va_arg(list, char *));
	return (0);
}
