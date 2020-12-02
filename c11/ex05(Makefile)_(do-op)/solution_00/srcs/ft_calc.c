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

int		ft_get_op(char c)
{
	if (c == '+')
		return (0);
	else if (c == '-')
		return (1);
	else if (c == '*')
		return (2);
	else if (c == '/')
		return (3);
	else if (c == '%')
		return (4);
	else
		return (5);
}

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

int		ft_div(int a, int b)
{
	return (a / b);
}

int		ft_mod(int a, int b)
{
	return (a % b);
}

int		ft_calc(int x, char operator, int y)
{
	int	(*g_p[5])(int x, int y);
	int temp;

	g_p[0] = ft_sum;
	g_p[1] = ft_sub;
	g_p[2] = ft_mul;
	g_p[3] = ft_div;
	g_p[4] = ft_mod;
	temp = ft_get_op(operator);
	if (temp == 5)
		return (0);
	return ((*g_p[temp])(x, y));
}

