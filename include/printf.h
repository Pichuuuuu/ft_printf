/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:27:21 by tamather          #+#    #+#             */
/*   Updated: 2020/02/14 11:15:32 by tamather         ###   ########.fr       */
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
	char flag[4];
	char width[20];
	char period;
	int precision;
	char format;
	
} pf;


int		ft_printf(const char *arg, ...);
int		pf_print(char *arg, va_list list);

//parsing function

pf      pf_parse_param(char *pos);
char	*parse_format(char *pos, pf *t);
char	*parse_precision(char *pos, pf t);

//display function

int		pf_formater(pf t, va_list list);

#endif