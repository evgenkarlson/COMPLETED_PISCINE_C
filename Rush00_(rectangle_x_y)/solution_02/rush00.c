/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 14:34:26 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 15:10:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	midline(int ix, int x)
{
	if (ix == 1 || ix == x)
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	firstlastline(int ix, int x)
{
	if (ix == 1 || ix == x)
		ft_putchar('o');
	else
		ft_putchar('-');
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
			if (iy == 1 || iy == y)
				firstlastline(ix, x);
			else
				midline(ix, x);
			ix++;
		}
		ft_putchar('\n');
		iy++;
	}
}
