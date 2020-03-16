/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:35:09 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/15 13:35:13 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include "ft_point.h"

t_point	find_next_empty(char grid[9][9], int x, int y)
{
	t_point p;

	x++;
	y++;
	p.x = 0;
	while (p.x < 9)
	{
		p.y = 0;
		while (p.y < 9)
		{
			if (!grid[p.x][p.y])
				return (p);
			p.y++;
		}
		p.x++;
	}
	return (p);
}

int		is_valid(char grid[9][9], t_point p, int n)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
		if (n == grid[p.x][i++])
			return (FALSE);
	i = 0;
	while (i < 9)
		if (n == grid[i++][p.y])
			return (FALSE);
	i = p.x / 3 * 3;
	while (i < p.x / 3 * 3 + 3)
	{
		j = p.y / 3 * 3;
		while (j < p.y / 3 * 3 + 3)
			if (n == grid[i][j++])
				return (FALSE);
		i++;
	}
	return (TRUE);
}

int		solve_sudoku_recur(char grid[9][9], t_point p, int *cnt)
{
	char	n;
	t_point	e;

	e = find_next_empty(grid, p.x, p.y);
	if (e.x > 8)
	{
		if (cnt)
			(*cnt)++;
		return (TRUE);
	}
	n = 1;
	while (n++ < 10)
		if (is_valid(grid, e, n - 1))
		{
			grid[e.x][e.y] = n - 1;
			if (solve_sudoku_recur(grid, e, cnt))
			{
				if (!cnt)
					return (TRUE);
				if (*cnt > 1)
					return (TRUE);
			}
			grid[e.x][e.y] = 0;
		}
	return (FALSE);
}

int		validate_state(char grid[9][9])
{
	t_point	p;
	int		n;

	p.x = 0;
	while (p.x < 9)
	{
		p.y = 0;
		while (p.y < 9)
		{
			n = grid[p.x][p.y];
			grid[p.x][p.y] = 0;
			if (n && !is_valid(grid, p, n))
				return (FALSE);
			grid[p.x][p.y] = n;
			p.y++;
		}
		p.x++;
	}
	return (TRUE);
}

int		solve_sudoku(char grid[9][9])
{
	t_point	p;
	int		solution_counter;
	char	solution[9][9];
	int		i;
	int		j;

	p.x = 0;
	p.y = 0;
	i = 9;
	while (i--)
	{
		j = 9;
		while (j--)
			solution[i][j] = grid[i][j];
	}
	if (!validate_state(solution))
		return (FALSE);
	solution_counter = 0;
	solve_sudoku_recur(solution, p, &solution_counter);
	if (solution_counter != 1)
		return (FALSE);
	return (solve_sudoku_recur(grid, p, 0));
}
