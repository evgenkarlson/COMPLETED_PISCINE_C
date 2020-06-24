/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_do_op.c                                :+:      :+:    :+:   */
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
	int i;

	if (((op[0] == '/') && !op[1]) && ft_atoi(b) == 0)
		ft_putstr("Stop : division by zero\n");
	else if (((op[0] == '%') && !op[1]) && ft_atoi(b) == 0)
		ft_putstr("Stop : modulo by zero\n");
	else
	{
		i = 0;
		while (i < 5)
		{
			if ((*g_opptab[i].op == op[0]) && !op[1])
			{
				ft_putnbr(g_opptab[i].func(ft_atoi(a), ft_atoi(b)));
				break;
			}
			i++;
		}
		if (i >= 5)
			g_opptab[5].func(ft_atoi(a), ft_atoi(b));
		ft_putchar('\n');
	}
}
