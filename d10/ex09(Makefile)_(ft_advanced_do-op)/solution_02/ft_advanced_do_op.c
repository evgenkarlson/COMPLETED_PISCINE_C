/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_do_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 01:43:15 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/25 14:45:55 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_advanced_do_op.h"
#include "ft_opp.h"

int	ft_usage(int a, int b)
{
	(void)a;
	(void)b;
	ft_putstr("error : only [ ");
	while (ft_strcmp(g_opptab[a].c, "") != 0)
	{
		ft_putstr(g_opptab[a].c);
		ft_putchar(' ');
		a++;
	}
	ft_putstr("] are accepted.\n");
	g_val = 1;
	return (0);
}

int	main(int argc, char **argv)
{
	int i;
	int result;

	result = 0;
	i = 0;
	if (argc != 4)
		return (0);
	while (i < 6)
	{
		if (ft_strcmp(argv[2], g_opptab[i].c) == 0)
		{
			result = g_opptab[i].f(ft_atoi(argv[1]), ft_atoi(argv[3]));
			if (!g_mod && !g_div)
				ft_putnbr(result);
			ft_putchar('\n');
			return (0);
		}
		i++;
	}
	ft_usage(0, 1);
	return (0);
}
