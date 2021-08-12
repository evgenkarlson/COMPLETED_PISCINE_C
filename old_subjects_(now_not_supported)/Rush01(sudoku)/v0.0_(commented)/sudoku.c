/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/12 17:38:56 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/08/12 12:28:40 by evgenkarlson     ###   ########.fr       */
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
	if (position == 80)
		return (1);
	if (tab[y][x] != '.')
		return (sudoku(tab, position + 1));
	while (++nb <= '9')
	{
		if (check_line(tab, nb, y) && check_column(tab, nb, x) && \
			check_block(tab, y, x, nb))
		{
			tab[y][x] = nb;
			if (sudoku(tab, position + 1))
				return (1);
		}
	}
	tab[y][x] = '.';
	return (0);
}
