/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 12:36:17 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/28 22:21:03 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		num_sides(int x, int y, int wid, int len)
{
	int num_sides;

	num_sides = 0;
	if ((x == 0) || (x == (wid - 1)))
		num_sides++;
	if ((y == 0) || (y == (len - 1)))
		num_sides++;
	return (num_sides);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

void	print_rush(char *rush, int *xy, int index, int num_rushes)
{
	ft_putstr("[");
	ft_putstr(rush);
	ft_putstr("] [");
	ft_putnbr(xy[0]);
	ft_putstr("] [");
	ft_putnbr(xy[1]);
	ft_putstr("]");
	if (index < num_rushes)
		ft_putstr(" || ");
}

void	ft_putnbr(int num)
{
	if (num == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (num < 0)
		{
			ft_putchar('-');
			num = num * -1;
		}
		if (num < 10)
			ft_putchar(num + '0');
		else
		{
			ft_putnbr(num / 10);
			ft_putchar((num % 10) + '0');
		}
	}
}
