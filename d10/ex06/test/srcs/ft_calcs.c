/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:54:47 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/24 14:57:27 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	sum(int a, int b, int *error)
{
	*error = 0;
	return (a + b);
}

int	subtract(int a, int b, int *error)
{
	*error = 0;
	return (a - b);
}

int	mul(int a, int b, int *error)
{
	*error = 0;
	return (a * b);
}

int	div(int a, int b, int *error)
{
	if (b)
		return (a / b);
	ft_putstr("Stop : division by zero");
	*error = 1;
	return (0);
}

int	mod(int a, int b, int *error)
{
	if (b)
		return (a % b);
	ft_putstr("Stop : modulo by zero");
	*error = 1;
	return (0);
}
