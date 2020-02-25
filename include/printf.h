/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:27:21 by tamather          #+#    #+#             */
/*   Updated: 2020/02/24 22:15:46 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct pf
{
	char *pos;
	int flagn;
	int flagO;
	int p_on;
	int O_on;
	int flagp;
	int precision;
	int width;
	char format;
	
} pf;


int		ft_printf(const char *arg, ...);
int		pf_print(char *arg, va_list list);
char	*pf_check_param(char *pos, va_list list, int *n);

//parsing function

pf      pf_parse_param(char *pos, va_list list);

//display function

int		pf_formater(pf t, va_list list);
void	ft_putstr_w_fd(char *s, int size, int fd);
int		digit_size(long i, int base);
void	ft_putnbr_base_fd(long n, int base, int up_on, int fd);

#endif