/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:27:21 by tamather          #+#    #+#             */
/*   Updated: 2020/02/12 09:20:59 by tamather         ###   ########.fr       */
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
    char flag;
    char mwidth;
    char period;
    char precision;
    char format;
    
} pf;


int		ft_printf(const char *arg, ...);
int		pf_print(const char *arg, va_list list);

//parsing function

pf      pf_parse_param(char *pos);

#endif