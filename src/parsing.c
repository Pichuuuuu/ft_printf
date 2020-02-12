/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:46:42 by tamather          #+#    #+#             */
/*   Updated: 2020/02/12 11:22:21 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

pf pf_parse_param(char *pos)
{
    int i;
    (void)pos;
    pf *t = NULL;
    (void)i;
    (void)t;
    return (*t);
}

char *parse_flag(char *pos, pf t)
{
    int i;

    i = 0;
    while (*pos)
    {
        if (*pos == ' ')
            pos++;
        else if(*pos == '-' || *pos == '0' || *pos == '.' || *pos == '*')
        {
            t.flag[i] = *pos;
            i++;
        }
        else
            break;
    }
    return 0;

}

char *parse_format(char *pos)
{
        while (*pos)
            if (*pos == 'c' || *pos == 's' || *pos == 'p'|| *pos == 'i' 
                || *pos == 'u' || *pos == 'x' || *pos == 'X' || *pos == '%')
                return (pos);
            else
                break;
        return (0);
}

