/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 20:44:40 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/21 20:44:42 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		solve_sudoku(int **numbers, int val);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

void	display_numbers(int **numbers)
{
	int x;
	int y;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			ft_putchar(numbers[x][y] + '0');
			if (y != 8)
				ft_putchar(' ');
			y += 1;
		}
		ft_putchar('\n');
		x += 1;
	}
}

int		**read_numbers(char **argv)
{
	int x;
	int y;
	int **numbers;

	x = 0;
	numbers = (int **)malloc(sizeof(int *) * 9 + 1);
	while (x < 9)
	{
		if (ft_strlen(argv[x]) != 9)
			return (0);
		numbers[x] = (int *)malloc(sizeof(int) * 9 + 1);
		y = 0;
		while (y < 9)
		{
			if (argv[x][y] == '.')
				numbers[x][y] = 0;
			else if (argv[x][y] >= '1' && argv[x][y] <= '9')
				numbers[x][y] = argv[x][y] - '0';
			else
				return (0);
			y += 1;
		}
		x += 1;
	}
	return (numbers);
}

int		main(int argc, char **argv)
{
	int **numbers;

	if (argc == 10)
	{
		numbers = read_numbers(&argv[1]);
		if (!numbers)
			write(1, "Error\n", 6);
		else if (solve_sudoku(numbers, 0))
			display_numbers(numbers);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
