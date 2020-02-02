/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 12:38:42 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/23 23:02:14 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	eval_expr(char *str)
{
	int result;

	result = 0;
	g_opstack.top = -1;
	g_rstack.top = -1;
	shunting_yard(str);
	result = calc_result(g_queue_array);
	return (result);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
