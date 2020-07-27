/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_adv_opp.h"
#include "../includes/ft_opp.h"


void	ft_advanced_do_op(char *a, char *op, char *b)
{
	int	i;

	i = 0;
	if (op[1])
		g_opptab[5].f(ft_atoi(a), ft_atoi(b));
	else if ((op[0] == '/') && (b == 0))
		ft_putstr("Stop : division by zero");
	else if ((op[0] == '%') && (b == 0))
		ft_putstr("Stop : modulo by zero");
	else
	{
		while (i < 5)
		{
			if ((*g_opptab[i].op == op[0]) && !op[1])
			{
				ft_putnbr(g_opptab[i].f(ft_atoi(a), ft_atoi(b)));
				break;
			}
			i++;
		}
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	if (argc == 4)
		ft_advanced_do_op(argv[1], argv[2], argv[3]);
	return (0);
}
