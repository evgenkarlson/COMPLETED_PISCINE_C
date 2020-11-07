/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_sum(int a, int b)
{
	return (a + b);
}

int		ft_sub(int a, int b)
{
	return (a - b);
}

int		ft_mul(int a, int b)
{
	return (a * b);
}

int		ft_mod(int a, int b)
{
	return (a % b);
}

int		ft_div(int a, int b)
{
	return (a / b);
}

int		ft_calc(int x, char operator, int y)
{
	int		i;
	t_cal	cal[5];

	/*	Инициализируем каждый обьект массива обьектов 'cal'*/
	cal[0].op = '+';
	cal[0].ft = ft_sum;

	cal[1].op = '-';
	cal[1].ft = ft_sub;

	cal[2].op = '*';
	cal[2].ft = ft_mul;

	cal[3].op = '/';
	cal[3].ft = ft_div;

	cal[4].op = '%';
	cal[4].ft = ft_mod;

/*
		V 0.2	Еще один способ инициализировать каждый обьект массива обьектов 'cal' 
		t_cal	cal[] = 
		{
			{'=', ft_sum},
			{'-', ft_sub},
			{'*', ft_mul},
			{'/', ft_div},
			{'%', ft_mod}
		};	

		V 0.3	Еще один способ инициализировать каждый обьект массива обьектов 'cal'
		cal[0] = (t_cal){.op = '+', .ft = ft_sum};
		cal[1] = (t_cal){.op = '-', .ft = ft_sub};
		cal[2] = (t_cal){.op = '*', .ft = ft_mul};
		cal[3] = (t_cal){.op = '/', .ft = ft_div};
		cal[4] = (t_cal){.op = '%', .ft = ft_mod};
*/

	i = 0;
	while (i < 5)
	{
		if (operator == cal[i].op)
			return(cal[i].ft(x, y));
		i++;
	}
	return (0);
}