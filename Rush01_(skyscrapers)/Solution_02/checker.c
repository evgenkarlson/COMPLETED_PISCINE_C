/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:03:23 by ecaceres          #+#    #+#             */
/*   Updated: 2019/08/10 17:03:26 by ecaceres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "boolean.h"
#include "constraint.h"
#include "checker.h"

t_bool	has_row_duplicate_value(int **grid, int size, int row)
{
	int	index;
	int	jndex;

	index = 0;
	while (index < size)
	{
		jndex = index + 1;
		while (jndex < size)
		{
			if (grid[row][index] == grid[row][jndex])
				return (true);
			jndex++;
		}
		index++;
	}
	return (false);
}

t_bool	validate_row(int **grid, t_constr row_constr, int row, int direction)
{
	int	column;
	int	seen;
	int	vision;
	int	memory;
	int	current;

	if (has_row_duplicate_value(grid, row_constr.size, row))
		return (false);
	column = 0;
	seen = 0;
	vision = row_constr.v[row];
	memory = -1;
	while (column < row_constr.size)
	{
		current = grid[row][column];
		if (direction == DIR_R_T_L)
			current = grid[row][row_constr.size - 1 - column];
		if (current > memory)
		{
			memory = current;
			seen++;
		}
		column++;
	}
	return (seen == vision);
}

t_bool	has_column_duplicate_value(int **grid, int size, int column)
{
	int	index;
	int	jndex;

	index = 0;
	while (index < size)
	{
		jndex = index + 1;
		while (jndex < size)
		{
			if (grid[index][column] == grid[jndex][column])
				return (true);
			jndex++;
		}
		index++;
	}
	return (false);
}

t_bool	validate_column(int **grid, t_constr col_constr, int col, int direction)
{
	int	row;
	int	seen;
	int	vision;
	int	memory;
	int	current;

	if (has_column_duplicate_value(grid, col_constr.size, col))
		return (false);
	row = 0;
	seen = 0;
	vision = col_constr.v[col];
	memory = -1;
	while (row < col_constr.size)
	{
		current = grid[row][col];
		if (direction == DIR_D_T_U)
			current = grid[col_constr.size - 1 - row][col];
		if (current > memory)
		{
			memory = current;
			seen++;
		}
		row++;
	}
	return (seen == vision);
}

t_bool	check_grid_validity(int **grid, int size, t_constr cnstr[4])
{
	int	row;
	int	column;

	row = 0;
	while (row < size)
	{
		if (!validate_row(grid, cnstr[LEFT], row, DIR_L_T_R)
			|| !validate_row(grid, cnstr[RIGHT], row, DIR_R_T_L))
			return (false);
		column = 0;
		while (column < size)
		{
			if (!validate_column(grid, cnstr[UP], column, DIR_U_T_D)
				|| !validate_column(grid, cnstr[DOWN], column, DIR_D_T_U))
				return (false);
			column++;
		}
		row++;
	}
	return (true);
}
