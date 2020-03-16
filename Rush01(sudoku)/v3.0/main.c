/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsheev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:49:06 by nsheev            #+#    #+#             */
/*   Updated: 2019/06/15 14:44:19 by nsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display(char s[9][9])
{
	int m;
	int n;

	m = 0;
	while (m < 9)
	{
		n = 0;
		while (n < 9)
		{
			ft_putchar(s[m][n] + '0');
			if (n < 8)
				ft_putchar(' ');
			n++;
		}
		m++;
		ft_putchar('\n');
	}
}

int		prepare_grid(char grid[9][9], int ac, char **av)
{
	int		i;
	int		j;
	char	e;

	if (ac != 10)
		return (FALSE);
	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			grid[i][j] = 0;
			e = av[i + 1][j];
			if (!e || (e != '.' && (e < '0' || e > '9')))
				return (FALSE);
			if (e != '.')
				grid[i][j] = e - '0';
			j++;
		}
		if (av[i + 1][j])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		main(int argc, char **argv)
{
	char	grid[9][9];

	if (!prepare_grid(grid, argc, argv))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!solve_sudoku(grid))
		write(1, "Error\n", 6);
	else
		display(grid);
	return (0);
}
