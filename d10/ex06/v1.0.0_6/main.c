/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <adespond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/16 00:31:57 by adespond          #+#    #+#             */
/*   Updated: 2015/09/16 05:34:11 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_op.h"

int		ft_do_op(int a, char op, int b)
{
	int		i;
	t_cal	cal[5];

	cal[0].op = '+';
	cal[0].f = ft_add;
	cal[1].op = '-';
	cal[1].f = ft_sub;
	cal[2].op = '*';
	cal[2].f = ft_mul;
	cal[3].op = '/';
	cal[3].f = ft_div;
	cal[4].op = '%';
	cal[4].f = ft_mod;
	i = 0;
	while (i < 5)
	{
		if (op == cal[i].op)
			return (cal[i].f(a, b));
		i++;
	}
	return (0);
}

int		check(char op, int b)
{
	if (op == '/' && b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	else if (op == '%' && b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (check(argv[2][0], ft_atoi(argv[3])))
		{
			ft_putnbr(ft_do_op(ft_atoi(argv[1]), argv[2][0], ft_atoi(argv[3])));
			ft_putchar('\n');
		}
	}
	return (0);
}
