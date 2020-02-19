/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 01:19:15 by tamather          #+#    #+#             */
/*   Updated: 2020/02/19 05:08:11 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include "libft/libft.h"

int main(int argc, char const *argv[])
{
	char test[] = "esdsfef";
	int test1 = -555444;
	double test2 = 54.3;
	//ft_printf("1er = %s\n2eme = %s\n3eme = %s\n", "lalala", "eeeee", "test 3");
	//printf("------------------------------------------------------------------------\n");
	//printf("1er = %s\n2eme = %s\n3eme = %s\n", "lalala", "eeeee", "test 3");
	//printf("|%04.*i| |%*f|", 6, test1, 5, test2);
	//printf("%d", ft_isalnum('6'));
	printf("|%*.*s|\n", 5, 5,  "testeee");
	ft_printf("|%*.*s|\n", 5, 5,  "testeee");
	//printf("|%*c,%5c|\n", 3, 't', 'e');
	//ft_printf("|%*c,%5c|\n", 3, 't', 'e');
	return 0;
}
