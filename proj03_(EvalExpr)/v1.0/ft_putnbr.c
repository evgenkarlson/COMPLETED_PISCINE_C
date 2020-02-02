/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 12:43:24 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/06 23:49:08 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c);

void	ft_printnbr(int x[])
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (i < 5)
	{
		if (b == 1)
		{
			ft_putchar(x[i] + 48);
		}
		else
		{
			if (x[i] > 0)
			{
				b = 1;
				ft_putchar(x[i] + 48);
			}
		}
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int o;
	int t;
	int x[5];

	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb + -2 * nb;
	}
	t = 4;
	while (t >= 0)
	{
		o = nb % 10;
		x[t] = o;
		nb /= 10;
		t--;
	}
	ft_printnbr(x);
}
