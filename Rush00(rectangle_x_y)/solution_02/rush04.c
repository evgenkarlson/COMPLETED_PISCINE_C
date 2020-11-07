/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 14:34:26 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 15:11:19 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	midline(int ix, int x)
{
	if (ix == 1 || ix == x)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	lastline(int ix, int x)
{
	if (ix == 1)
		ft_putchar('C');
	else if (ix == x)
		ft_putchar('A');
	else
		ft_putchar('B');
}

void	firstline(int ix, int x)
{
	if (ix == 1)
		ft_putchar('A');
	else if (ix == x)
		ft_putchar('C');
	else
		ft_putchar('B');
}

void	rush(int x, int y)
{
	int ix;
	int iy;

	iy = 1;
	while (iy <= y)
	{
		ix = 1;
		while (ix <= x)
		{
			if (iy == 1)
				firstline(ix, x);
			else if (iy == y)
				lastline(ix, x);
			else
				midline(ix, x);
			ix++;
		}
		ft_putchar('\n');
		iy++;
	}
}
