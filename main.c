/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 01:19:15 by tamather          #+#    #+#             */
/*   Updated: 2020/02/12 11:26:29 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include "libft/libft.h"

int main(int argc, char const *argv[])
{
	char test[] = "esdsfef";
	int test1 = 444;
	char test2 = 'e';
	//ft_printf(argv[1]);
	printf("|%.5i|", test1);
	//printf("%d", ft_isalnum('6'));
	return 0;
}







