/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 01:19:15 by tamather          #+#    #+#             */
/*   Updated: 2020/02/22 18:00:13 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"
#include "libft/libft.h"

int main(int argc, char const *argv[])
{
	char test[] = "esdsfef";
	char *p = test;
	int test1 = -555444;
	double test2 = 54.3;
	//ft_printf("1er = %s\n2eme = %s\n3eme = %s\n", "lalala", "eeeee", "test 3");
	//printf("------------------------------------------------------------------------\n");
	//printf("1er = %s\n2eme = %s\n3eme = %s\n", "lalala", "eeeee", "test 3");
	//printf("|%04.*i| |%*f|", 6, test1, 5, test2);
	//printf("%d", printf("Simple input test"));
	//printf("%d\n", printf("|%*.*s| -- ", 10, 3, "test"));
	//printf("%d\n", ft_printf("|%*.*s| -- ", 10, 3, "test"));
	//printf("|%*c,%5c|\n", 3, 't', 'e');
	//ft_printf("|%*c,%5c|\n", 3, 't', 'e');
	//printf(" |%d|\n", printf("|%10d|", 333));
	//printf(" |%d|\n", ft_printf("|%10d|", 333));
	printf("%-.1xN78AU%.4uv%-18cOQiV8uB\n", -2147483647, 1653343193, 'K');
	ft_printf("%-.1xN78AU%.4uv%-18cOQiV8uB\n", -2147483647, 1653343193, 'K');
	//ft_putnbr_base_fd(-205, 16, 0, 1);
	return 0;
}
