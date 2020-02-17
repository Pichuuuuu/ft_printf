/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:46:42 by tamather          #+#    #+#             */
/*   Updated: 2020/02/17 17:09:16 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../libft/libft.h"

char *parse_width(char *pos, pf **t)
{
	int i;

	i = 0;
	while (*pos && i < 20)
{
		if (ft_isdigit(*pos))
		{
			(**t).width[i] = *pos;
			i++;
		}
		else
			break;
		pos++;
	}
	(**t).width[i] = '\0';
	return (pos);
}

void	parse_flag(char *pos, pf *t)
{
	int i;

	i = 0;
	(*t).precision = 0;
	while (*pos && i < 4)
	{
		if (*pos == '-' || *pos == '0' || *pos == '.')
			(*t).flag[i++] = *pos;
		else if(*pos == '*')
			(*t).precision = 1;
		else if (ft_isdigit(*pos))
			pos = parse_width(pos, &t);
		else 
			break;
		pos++;
	}
	(*t).flag[i] = '\0';
	(*t).pos = pos;
}

void	parse_format(char *pos, pf *t)
{

	if (*pos == 'c' || *pos == 's' || *pos == 'p'|| *pos == 'i' || 
		*pos == 'u' || *pos == 'x' || *pos == 'X' || *pos == '%' || *pos == 'd')
		(*t).format = *pos;
	(*t).pos = pos;
}

pf pf_parse_param(char *pos)
{
	pf t;
	t.pos = pos;
	parse_flag(t.pos, &t);
	parse_format(t.pos, &t);
	return (t);
}