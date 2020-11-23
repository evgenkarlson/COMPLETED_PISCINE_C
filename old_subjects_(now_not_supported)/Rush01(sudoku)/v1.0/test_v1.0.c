/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_v1.0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 15:03:46 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


/*

One solution:
gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......." | cat -e
9 1 4 3 7 5 2 6 8$
2 8 7 4 9 6 1 5 3$
3 6 5 8 1 2 4 7 9$
8 4 6 5 2 1 3 9 7$
5 2 9 6 3 7 8 1 4$
7 3 1 9 8 4 5 2 6$
1 5 3 7 4 9 6 8 2$
6 9 8 2 5 3 7 4 1$
4 7 2 1 6 8 9 3 5$

Multiple Solutions:
gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out "9.6.7.4.3" "...4..2.." ".7..23.1." "5.....1.." ".4.2.8.6." "..3.....5" ".3.7...5." "..7..5..." "4.5.1.7.8" | cat -e
9 2 6 5 7 1 4 8 3$
3 5 1 4 8 6 2 7 9$
8 7 4 9 2 3 5 1 6$
5 8 2 3 6 7 1 9 4$
1 4 9 2 5 8 3 6 7$
7 6 3 1 4 9 8 2 5$
2 3 8 7 9 4 6 5 1$
6 1 7 8 3 5 9 4 2$
4 9 5 6 1 2 7 3 8$

Expert level:
gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out ".8...3.57" "7........" "..4....86" "........." "....7.46." "629..8..." ".5...689." "........." ".....21.3"
9 2 6 5 7 1 4 8 3$
3 5 1 4 8 6 2 7 9$
8 7 4 9 2 3 5 1 6$
5 8 2 3 6 7 1 9 4$
1 4 9 2 5 8 3 6 7$
7 6 3 1 4 9 8 2 5$
2 3 8 7 9 4 6 5 1$
6 1 7 8 3 5 9 4 2$
4 9 5 6 1 2 7 3 8$

*/

#include <stdlib.h>
#include <unistd.h>

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

int		validate(int **numbers, int row, int col, int value)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		if ((numbers[i][col] == value) || (numbers[row][i] == value))
			return (0);
		i += 1;
	}
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (numbers[row - (row % 3) + i][col - (col % 3) + j] == value)
				return (0);
			j += 1;
		}
		i += 1;
	}
	return (1);
}

int		solve_sudoku(int **numbers, int value)
{
	int i;
	int x;
	int y;

	i = 1;
	x = value / 9;
	y = value % 9;
	if (value == 81)
		return (1);
	if (numbers[x][y] != 0)
		return (solve_sudoku(numbers, value + 1));
	while (i < 10)
	{
		if (validate(numbers, x, y, i))
		{
			numbers[x][y] = i;
			if (solve_sudoku(numbers, value + 1))
				return (1);
			else
				numbers[x][y] = 0;
		}
		i += 1;
	}
	return (0);
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
