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
	int		x;
	int		y;
	char	nb;

	nb = '0';
	x = position / 9;
	y = position % 9;
	if (position == 90)
		return (1);
	if (tab[x][y] != '.')
		return (sudoku(tab, position + 1));
	while (++nb <= '9')
	{
		if (check_line(tab, nb, x) + check_column(tab, nb, y) == 2)
		{
			if (check_block(tab, x, y, nb) == 1)
			{
				tab[x][y] = nb;
				if (sudoku(tab, position + 1))
					return (1);
			}
		}
	}
	tab[x][y] = '.';
	return (0);
}
