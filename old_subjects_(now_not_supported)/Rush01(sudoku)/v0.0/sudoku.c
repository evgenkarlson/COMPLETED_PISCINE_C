/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 17:38:56 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 15:02:55 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	sudoku(char **tab, int position)
{
	int		y;
	int		x;
	char	nb;

	nb = '0';
	y = position / 9;
	x = position % 9;
	if (position == 90)
		return (1);
	if (tab[y][x] != '.')
		return (sudoku(tab, position + 1));
	while (++nb <= '9')
	{
		if (check_line(tab, nb, y) + check_column(tab, nb, x) == 2)
		{
			if (check_block(tab, y, x, nb) == 1)
			{
				tab[y][x] = nb;
				if (sudoku(tab, position + 1))
					return (1);
			}
		}
	}
	tab[y][x] = '.';
	return (0);
}
