/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 08:46:42 by tamather          #+#    #+#             */
/*   Updated: 2020/02/19 06:01:47 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include "../libft/libft.h"

int width_size(char **pos)
{
	int res;

	res = ft_atoi(*pos);
	while (ft_isdigit(*(*pos + 1)))
		(*pos)++;
	return (res);
}

int p_size(char **pos)
{
	int res;
	if(ft_isdigit(*(*pos + 1)) && ft_atoi(*pos + 1) != 0)
		res = ft_atoi(*pos + 1);
	else
		res = -1;
	while (ft_isdigit(*(*pos + 1)))
		(*pos)++;
	return (res);
}

void	parse_flag(char *pos, pf *t, va_list list)
{
	int i;

	i = 0;
	while (*pos)
	{
		if (*pos == '-' )
			(*t).flagn = 1;
		else if (*pos == '0')
			;
		else if (*pos == '.')
			(*t).size = p_size(&pos);
		else if(*pos == '*')
			(*t).precision[i++] = va_arg(list, int);
		else if (ft_isdigit(*pos))
			(*t).width = width_size(&pos);
		else
			break;
		pos++;
	}
	(*t).pos = pos;
}

void	parse_format(char *pos, pf *t)
{

	if (*pos == 'c' || *pos == 's' || *pos == 'p'|| *pos == 'i' || 
		*pos == 'u' || *pos == 'x' || *pos == 'X' || *pos == '%' || *pos == 'd')
		(*t).format = *pos;
	(*t).pos = pos;
}

pf pf_parse_param(char *pos, va_list list)
{
	pf t;
	
	t.precision[0] = 0;
	t.width = 0;
	t.size = 0;
	t.pos = pos;
	parse_flag(t.pos, &t, list);
	parse_format(t.pos, &t);
	printf("|%d, %d|", t.precision[0], t.precision[1]);
	return (t);
}