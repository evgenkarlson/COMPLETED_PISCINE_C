/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jevan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 10:38:43 by jevan-de      #+#    #+#                 */
/*   Updated: 2020/02/12 20:52:12 by tclement      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFSIZE 4097

int		find_y(char *map)
{
	int y;
	int index;

	y = 0;
	index = 0;
	while (map[index] != '\0')
	{
		if (map[index] == '\n')
			y++;
		index++;
	}
	return (y - 1);
}

int		find_x(char *map)
{
	int x;
	int index;
	int newline_count;

	index = 0;
	x = 0;
	newline_count = 0;
	while (newline_count != 2)
	{
		if (newline_count == 1 && map[index] != '\n')
			x++;
		if (map[index] == '\n')
			newline_count++;
		index++;
	}
	return (x);
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

char	get_char(char *map, int y, int pos)
{
	int		value;
	int		digits;

	digits = 0;
	value = y;
	while (value != 0)
	{
		value = value / 10;
		digits++;
	}
	return (map[digits + pos]);
}

int		get_max_size(int **grid, int col, int row, int size, int xmax, int ymax)
{
	int		index;
	int		i;
	int		sum;

	if (grid[row][col] != 0)
		return (size - 1);
	else
	{
		sum = 0;
		index = 0;
		while (index < size)
		{
			i = 0;
			while (i < size)
			{
				sum += grid[row + index][col + i];
				i++;
			}
			index++;
		}
		if (sum == 0)
		{
			if (size == (ymax - row) || size == (xmax - col))
				return (size);
			else
				return (get_max_size(grid, col, row, size + 1, xmax, ymax));
		}
		else
			return (size - 1);
	}
}

int		**find_square(int **grid, int x, int y)
{
	int		**final_grid;
	int		*p;
	int		col;
	int		row;

	printf("\n");
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
			printf("%d ", final_grid[row][col]);
			col++;
		}
		row++;
		printf("\n");
	}
	return (final_grid);
}

int		find_max(int **final, int *row, int *col, int x, int y)
{
	int		index;
	int		i;
	int		size;

	index = 0;
	size = 0;
	while (index < y)
	{
		i = 0;
		while (i < x)
		{
			if (final[index][i] > size)
			{
				size = final[index][i];
				*row = index;
				*col = i;
			}
			i++;
		}
		index++;
	}
	return (size);
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
	printf("\n");
	while (index < y)
	{
		i = 0;
		while (i < x)
		{
			if ((index >= row && index < (row + size)) && (i >= col && i < (col + size)))
				write(1, &fill, 1);
			else
				write(1, (rows[index] + i), 1);
			i++;
		}
		printf("\n");
		index++;
	}
}

int		**build_grid(int **grid, char *map, int x, int y)
{
	char	**rows;
	int		index;
	int		i;

	index = 0;
	rows = split_rows(map, x, y);
	grid = (int**)malloc(sizeof(int*) * y);
	while (index < y)
	{
		i = 0;
		*grid = convert_row(rows[index], x, get_char(map, y, 0), get_char(map, y, 1));
		while (i < x)
		{
			printf("%d ", (*grid)[i]);
			i++;
		}
		printf("\n");
		index++;
		grid++;
	}
	grid -= index;
	return (grid);
}

int		main(int argc, char **argv)
{
	char	**maps;
	int		**grid;
	int		**final;
	int		index;
	int		fd;
	int		size;

	index = 1;
	maps = (char**)malloc(sizeof(char*) * (argc - 1));
	while (index < argc)
	{
		fd = open(argv[index], O_RDONLY);
		if (fd == -1)
			write(2, "map error\n", 10);
		else
		{
			*maps = (char*)malloc(sizeof(char) * BUFFSIZE);
			size = read(fd, *maps, BUFFSIZE);
			if (size == BUFFSIZE)
				write(2, "map error\n", 10);
			else
			{
				(*maps)[size] = '\0';
				grid = build_grid(grid, *maps, find_x(*maps), find_y(*maps));
				final = find_square(grid, find_x(*maps), find_y(*maps));
				print_map(final, *maps);
			}
		}
		index++;
		maps++;
	}
	return (0);
}
