/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 08:52:06 by tamather          #+#    #+#             */
/*   Updated: 2020/02/14 11:18:34 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../libft/libft.h"

int		pf_formater(pf t, va_list list)
{
	write(1, "e", 1);
	va_list test;
	int te;
	va_start(test, te);
	return (0);
}

int		display_string(pf t, char *string)
{
	ft_putstr_fd(string, 1);
}