/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:27:21 by tamather          #+#    #+#             */
/*   Updated: 2020/02/01 01:01:49 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdio.h>
# include <unistd.h>

typedef struct pf
{
    char *pos;
    char flag;
    char mwidth;
    char period;
    char precision;
    char conversion;
    
} pf;

int		ft_printf(const char *, ...);


#endif