/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:57:09 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/08 21:26:01 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

void		ft_putnbr(int nbr)
{
	int	count;
	int	temp;

	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nbr = 147483648;
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	temp = nbr;
	count = 1;
	while ((temp /= 10))
		count *= 10;
	while (count)
	{
		ft_putchar((nbr / count) + '0');
		nbr %= count;
		count /= 10;
	}
}
