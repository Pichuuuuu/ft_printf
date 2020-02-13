/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 01:19:15 by tamather          #+#    #+#             */
/*   Updated: 2020/02/13 08:54:26 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include "libft/libft.h"

int main(int argc, char const *argv[])
{
	char test[] = "esdsfef";
	int test1 = -555444;
	int test2 = 54;
	//ft_printf(argv[1]);
	printf("|%0.*i| |%*i|", 700, test1, 5, test2);
	//printf("%d", ft_isalnum('6'));
	return 0;
}







