/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:27:21 by tamather          #+#    #+#             */
/*   Updated: 2020/02/27 03:44:53 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_pf
{
	char	*pos;
	int		flagn;
	int		flago;
	int		p_on;
	int		o_on;
	int		flagp;
	int		pre;
	int		width;
	char	format;
}				t_pf;

int				ft_printf(const char *arg, ...);
int				pf_print(char *arg, va_list list);
char			*pf_check_param(char *pos, va_list list, int *n);
t_pf			pf_parse_param(char *pos, va_list list);
int				pf_formater(t_pf t, va_list list);
void			ft_putstr_w_fd(char *s, int size, int fd);
int				digit_size(long i, int base);
void			ft_putnbr_base_fd(long n, int base, int up_on, int fd);
int				zero(t_pf t, long digit);
int				separator(t_pf t, int size);
#endif
