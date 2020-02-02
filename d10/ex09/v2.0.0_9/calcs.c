/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:54:47 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/25 14:37:23 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_advanced_do_op.h"

int	ft_add(int a, int b)
{
	return (a + b);
}

int	ft_sub(int a, int b)
{
	return (a - b);
}

int	ft_mul(int a, int b)
{
	return (a * b);
}

int	ft_div(int a, int b)
{
	if (b)
		return (a / b);
	ft_putstr("Stop : division by zero");
	g_div = 1;
	return (0);
}

int	ft_mod(int a, int b)
{
	if (b)
		return (a % b);
	ft_putstr("Stop : modulo by zero");
	g_mod = 1;
	return (0);
}
