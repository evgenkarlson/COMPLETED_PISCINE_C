/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flklein <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:17:17 by flklein           #+#    #+#             */
/*   Updated: 2018/09/09 21:57:42 by flklein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		this_is_the_end(int **tab, int **tab_cpy, int *res)
{
	if (*res == 0)
		copy_tab(tab_cpy, tab);
	(*res)++;
	if (*res == 2)
		return (1);
	return (0);
}

int		solve_sudoku(int **tab, int **tab_cpy, int *res, int pos)
{
	int		l;
	int		c;
	int		nb;

	if (pos == 81)
		return (this_is_the_end(tab, tab_cpy, res));
	l = pos / 9;
	c = pos % 9;
	if (tab[l][c] != 0)
		return (solve_sudoku(tab, tab_cpy, res, pos + 1));
	nb = 1;
	while (nb <= 9)
	{
		if (test(tab, l, c, nb))
		{
			tab[l][c] = nb;
			if (solve_sudoku(tab, tab_cpy, res, pos + 1))
				return (1);
		}
		nb++;
	}
	tab[l][c] = 0;
	return (0);
}

int		main(int ac, char **av)
{
	int		**tab;
	int		**tab_cpy;
	int		res;

	if (ac != 10 || !(tab = create_tab(av))
			|| !(tab_cpy = create_tab(av)) || !(is_valid(tab)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	solve_sudoku(tab, tab_cpy, &res, 0);
	if (res == 1)
		print_tab(tab_cpy);
	else
		write(1, "Error\n", 6);
	return (0);
}
