/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 02:56:50 by tamather          #+#    #+#             */
/*   Updated: 2020/02/20 22:21:21 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_w_fd(char *s, int size, int fd)
{
    int i;

    i = 0;
	while (*s && i < size)
    {
		write(fd, s++, 1);
        i++;
    }
}

int		int_size(int i)
{
	int c;

	c = 0;
	while (i > 10)
	{
		i /= 10;
		c++;
	}
	return (c + 1);
}