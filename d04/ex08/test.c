/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 23:16:39 by jaleman           #+#    #+#             */
/*   Updated: 2016/04/01 23:16:40 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*  	команда для компиляции и одновременного запуска                       */
/*                                                                            */
/*         gcc test.c && chmod +x ./a.out && ./a.out	                      */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	
	return (0);
}

void	dessin(int *board)
{
	int x;
	int y;

	x = 0;

	while (x++ < 8)
	{
		ft_putchar(x+'0');
		ft_putchar('|');
		y = 0;
		while (y++ < 8)
		{
			ft_putchar(' ');
			if (board[x - 1] == y)
				ft_putchar('&');
			else
				ft_putchar('.');
		}
		ft_putchar(' ');
		ft_putchar('\n');
	}	
		ft_putchar('\n');
		ft_putchar('\n');
}

int		placement(int y, int x, int *board)
{
	if(y >= 8 && x >= 8)
		return (0);
	if(x >= 8)
	{
		y++;
		x = 0;
	}
	else
		x++;

	ft_putchar('y');
	ft_putchar(' ');
	ft_putchar(y + '0');
	ft_putchar(' ');
	ft_putchar(' ');
	ft_putchar(' ');
	ft_putchar(' ');
	ft_putchar('x');
	ft_putchar(' ');
	ft_putchar(x + '0');
	placement(y, x, board);
	return (0);
}

int		check(int y, int x, int *board)
{
	int i;
	i = 0;
	while(i++ < y)
	{
		if(board[i] == x)
			return (0);
		if(board[i] - (y - i) == x)
			return (0);
		if(board[i] + (y - i) == x)
			return (0);
	}
	return (1);
}

int		ft_eight_queens_puzzle(void)
{
	int board[8];
	board[0] = 4;
	board[1] = 1;
	board[2] = 3;
	board[3] = 2;
	board[4] = 1;
	board[5] = 6;
	board[6] = 7;
	board[7] = 8;

	dessin(board);

	return (0);
}

int		main(void)
{
	ft_eight_queens_puzzle();
	return (0);
}


/* ************************************************************************** */
