/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-thie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:57:35 by ple-thie          #+#    #+#             */
/*   Updated: 2018/07/25 18:56:43 by ple-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

void	ft_putnbr(int nb)
{
	long nbr_long;

	nbr_long = nb;
	if (nbr_long < 0)
	{
		ft_putchar('-');
		nbr_long = -nbr_long;
	}
	if (nbr_long >= 10)
	{
		ft_putnbr(nbr_long / 10);
	}
	ft_putchar('0' + nbr_long % 10);
}
