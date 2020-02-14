/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:46:42 by tamather          #+#    #+#             */
/*   Updated: 2020/02/14 09:11:40 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../libft/libft.h"

char *parse_flag(char *pos, pf t)
{
	int i;

	i = 0;
	while (*pos && i < 4)
	{
		if (*pos == ' ')
			pos++;
		else if (*pos == '-' || *pos == '0' || *pos == '.' || *pos == '*')
		{
			t.flag[i] = *pos;
			i++;
		}
		else
			break;
	}
	return (pos);

}

char *parse_width(char *pos, pf t)
{
	int i;

	i = 0;
	while (*pos && i < 20)
{
		if (ft_isdigit(*pos))
		{
			t.width[i] = *pos;
			i++;
		}
		else
			break;
	}
	return (pos);
}

char *parse_precision(char *pos, pf t)
{
	if(*pos == '*')
		t.precision = 1;
	else
		t.precision = 0;
	return(pos);
}

char *parse_format(char *pos, pf *t)
{
		while (*pos)
			if (*pos == 'c' || *pos == 's' || *pos == 'p'|| *pos == 'i' 
				|| *pos == 'u' || *pos == 'x' || *pos == 'X' || *pos == '%')
			{
				(*t).format = *pos;
				return (pos);
			}
			else
				break;
		return (pos);
}

pf pf_parse_param(char *pos)
{
	pf t;

	t.pos = pos;
	parse_format(t.pos, &t);
	
	return (t);
}