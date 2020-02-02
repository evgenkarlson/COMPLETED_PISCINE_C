/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtia <mcourtia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/06 14:34:26 by mcourtia          #+#    #+#             */
/*   Updated: 2015/09/06 16:42:44 by mcourtia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	midline(int ix, int x)
{
	if (ix == 1 || ix == x)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	lastline(int ix, int x)
{
	if (ix == 1)
		ft_putchar('\\');
	else if (ix == x)
		ft_putchar('/');
	else
		ft_putchar('*');
}

void	firstline(int ix, int x)
{
	if (ix == 1)
		ft_putchar('/');
	else if (ix == x)
		ft_putchar('\\');
	else
		ft_putchar('*');
}

void	colle(int x, int y)
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
