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
