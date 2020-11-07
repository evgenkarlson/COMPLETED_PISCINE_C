/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpucelle <jpucelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/22 12:37:48 by jpucelle          #+#    #+#             */
/*   Updated: 2014/07/23 18:16:17 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

void	jp_putchar(char c)
{
	write(1, &c, 1);
}

void	jp_putnbr(int nbr)
{
	if (nbr >= 10)
	{
		jp_putnbr(nbr / 10);
		jp_putnbr(nbr % 10);
	}
	else
	{
		jp_putchar(nbr + '0');
	}
}

void	jp_putstr(char *str)
{
	write(1, &str[0], jp_strlen(str));
}

void	jp_puterr(char *str)
{
	write(2, &str[0], jp_strlen(str));
}
