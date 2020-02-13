/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:46:42 by tamather          #+#    #+#             */
/*   Updated: 2020/02/13 08:21:46 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../libft/libft.h"

pf pf_parse_param(char *pos)
{
	int i;
	(void)pos;
	pf *t = 0;
	(void)i;
	(void)t;
	return (*t);
}

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

char *parse_format(char *pos)
{
		while (*pos)
			if (*pos == 'c' || *pos == 's' || *pos == 'p'|| *pos == 'i' 
				|| *pos == 'u' || *pos == 'x' || *pos == 'X' || *pos == '%')
				return (pos);
			else
				break;
		return (pos);
}

