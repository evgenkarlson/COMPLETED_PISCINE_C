/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 10:38:43 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/02/12 22:02:09 by jevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "helpers.h"

int		**find_square(int **grid, int x, int y)
{
	int		**final_grid;
	int		*p;
	int		col;
	int		row;

	row = 0;
	final_grid = (int**)malloc(sizeof(int*) * y);
	while (row < y)
	{
		col = 0;
		p = (int*)malloc(sizeof(int) * x);
		final_grid[row] = p;
		while (col < x)
		{
			final_grid[row][col] = get_max_size(grid, col, row, 1, x, y);
			col++;
		}
		row++;
	}
	return (final_grid);
}

int		*convert_row(char *row, int x, char empty, char obstacle)
{
	int		*irow;
	int		index;

	index = 0;
	irow = (int*)malloc(sizeof(int) * x);
	while (row[index] != '\0')
	{
		if (row[index] == empty)
			irow[index] = 0;
		else if (row[index] == obstacle)
			irow[index] = 1;
		else
		{
			free(irow);
			irow = NULL;
			return (irow);
		}
		index++;
	}
	return (irow);
}

char	**split_rows(char *map, int x, int y)
{
	char	**rows;
	char	*p;
	int		index;
	int		newline_count;

	newline_count = 0;
	index = 0;
	rows = (char**)malloc(sizeof(char*) * y);
	p = (char*)malloc(sizeof(char) * x);
	while (map[index] != '\0')
	{
		if (map[index] == '\n')
			newline_count++;
		if (newline_count >= 1 && !(newline_count == 1 && map[index] == '\n'))
		{
			*p = map[index];
			if (map[index] == '\n')
			{
				*p = '\0';
				p = p - x;
				*rows = p;
				if (newline_count != (y + 1))
				{
					p = (char*)malloc(sizeof(char) * x);
					rows++;
				}
			}
			p++;
		}
		index++;
	}
	rows -= (y - 1);
	return (rows);
}

int		**build_grid(int **grid, char *map, int x, int y)
{
	char	**rows;
	int		*p;
	int		index;

	index = 0;
	rows = split_rows(map, x, y);
	grid = (int**)malloc(sizeof(int*) * y);
	while (index < y)
	{
		p = convert_row(rows[index], x,
				get_char(map, y, 0), get_char(map, y, 1));
		if (!p)
		{
			grid = NULL;
			return (grid);
		}
		*grid = p;
		index++;
		grid++;
	}
	grid -= index;
	return (grid);
}

void	print_map(int **final, char *map)
{
	char	fill;
	char	**rows;
	int		col;
	int		row;
	int		size;
	int		index;
	int		i;
	int		x;
	int		y;

	x = find_x(map);
	y = find_y(map);
	fill = get_char(map, find_y(map), 2);
	size = find_max(final, &row, &col, x, y);
	rows = split_rows(map, x, y);
	index = 0;
	while (index < y)
	{
		i = 0;
		while (i < x)
		{
			if ((index >= row && index < (row + size))
					&& (i >= col && i < (col + size)))
				write(1, &fill, 1);
			else
				write(1, (rows[index] + i), 1);
			i++;
		}
		write(1, "\n", 1);
		index++;
	}
	write(1, "\n", 1);
}
