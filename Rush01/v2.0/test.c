/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


#include <unistd.h>

void		jp_putchar(char c)
{
	write(1, &c, 1);
}

int			jp_parse_sudoku_table(int pos[9][9], char **argv)
{
	int		ix;
	int		iy;

	iy = 0;
	while (iy < 9)
	{
		ix = 0;
		while (ix < 9)
		{
			if (argv[iy][ix] >= '0' && argv[iy][ix] <= '9')
				pos[iy][ix] = argv[iy][ix] - '0';
			else if (argv[iy][ix] == '.')
				pos[iy][ix] = 0;
			else
				return (0);
			ix++;
		}
		if (argv[iy][ix])
			return (0);
		iy++;
	}
	return (1);
}

void		jp_print_sudoku(int pos[9][9])
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			jp_putchar(pos[i][j] + 48);
			if (j != 8)
				jp_putchar(' ');
			j++;
		}
		jp_putchar('\n');
		i++;
	}
}

void		jp_set_pos(int *pos, int *orig, int i, int check)
{
	*pos = i;
	if (check == 0)
		*orig = i;
}

int			jp_check_square(int pos[9][9], int x, int y, int nbr)
{
	int		xmin;
	int		xmax;
	int		ymin;
	int		ymax;
	int		i;

	xmin = (x / 3) * 3;
	xmax = xmin + 3;
	ymin = (y / 3) * 3;
	ymax = ymin + 3;
	while (xmin < xmax)
	{
		i = ymin;
		while (i < ymax)
		{
			if (i != y && xmin != x && pos[i][xmin] == nbr)
				return (0);
			i++;
		}
		xmin++;
	}
	return (1);
}

int			jp_check_pos(int pos[9][9], int x, int y, int nbr)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (i != x && pos[y][i] == nbr)
			return (0);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		if (i != y && pos[i][x] == nbr)
			return (0);
		i++;
	}
	i = jp_check_square(pos, x, y, nbr);
	return (i);
}

void		jp_put_last_nr(int pos[9][9], int nr, int *check)
{
	if (jp_check_pos(pos, 8, 8, nr))
	{
		if (pos[8][8] == 0)
			pos[8][8] = nr;
		*check = *check + 1;
	}
}

void		jp_solve(int pos[9][9], int val, int orig[9][9], int *check)
{
	int		i;
	int		x;
	int		y;

	x = val % 9;
	y = val / 9;
	if (pos[y][x] != 0 && (x != 8 || y != 8) && *check < 2)
		jp_solve(pos, val + 1, orig, check);
	i = 1;
	while (i < 10 && *check < 2)
	{
		if (x != 8 || y != 8)
		{
			if (jp_check_pos(pos, x, y, i) && pos[y][x] == 0)
			{
				jp_set_pos(&pos[y][x], &orig[y][x], i, *check);
				jp_solve(pos, val + 1, orig, check);
				pos[y][x] = 0;
			}
		}
		else
			jp_put_last_nr(orig, i, check);
		i++;
	}
}

int			main(int argc, char **argv)
{
	int		pos[9][9];
	int		orig[9][9];
	int		check;
	int		*ptr_check;

	check = 0;
	ptr_check = &check;
	if (argc == 10)
	{
		jp_parse_sudoku_table(orig, &argv[1]);
		if (jp_parse_sudoku_table(pos, &argv[1]))
		{
			jp_solve(pos, 0, orig, ptr_check);
			if (check == 1)
				jp_print_sudoku(orig);
			else
				write(1, "Erreur\n", 7);
		}
		else
			write(1, "Erreur\n", 7);
	}
	return (0);
}
