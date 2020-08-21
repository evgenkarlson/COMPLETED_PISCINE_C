/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 20:07:07 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 20:57:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : checkmate 
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program who takes rows of a chessboard in argument and check if your King is in a check position.
Напишите программу, в которой аргументы принимаются за строки шахматной доски, и проверьте, находится ли ваш король в проверочной позиции.

Chess is played on a chessboard, a squared board of 8-squares length with specific pieces on it : King, Queen, Bishop, Knight, Rook and Pawns. For this exercice, you will only play with Pawns, Bishops, Rooks and Queen... and obviously a King.
В шахматы играют на шахматной доске, квадратной доске длиной 8 квадратов с определенными фигурами на ней: король, королева, епископ, рыцарь, ладья и пешки.
В этом упражнении вы будете играть только с пешками, слонами, ладьями и королевой ... и, очевидно, с королем.

Each piece have a specific method of movement, and all patterns of capture are detailled in the examples.txt file.
У каждой части есть определенный метод движения, и все образцы захвата подробно описаны в файле examples.txt.

A piece can capture only the first ennemy piece it founds on its capture patterns.
Часть может захватить только первую вражескую фигуру, которую она находит на своих образцах захвата.

The board have a variable size but will remains a square. There's only one King and all other pieces are against it. All other characters except those used for pieces are considered as empty squares.
Доска имеет переменный размер, но остается квадратом. Есть только один король, а все остальные фигуры против. Все остальные символы, кроме используемых для фигур, считаются пустыми квадратами.

The King is considered as in a check position when an other enemy piece can capture it. When it's the case, you will print "Success" on the standard output followed by a newline, otherwise you will print "Fail" followed by a newline.
Король считается находящимся в контрольном положении, когда другая вражеская фигура может захватить его. В этом случае вы напечатаете «Success» на стандартном выводе, за которым следует новая строка, в противном случае вы напечатаете «Fail», за которым следует новая строка.

If there is no arguments, the program will only print a newline.
Если аргументов нет, программа напечатает только новую строку.





Examples:

$> ./chessmate '..' '.K' | cat -e
Fail$
$> ./chessmate 'R...' '..P.' '.K..' '....' | cat -e
Success$
$> ./chessmate 'R...' 'iheK' '....' 'jeiR' | cat -e
Success$
$> ./chessmate | cat -e
$
$>



Examples:
Примеры:

Pion / Pawn (P):

	. . . . . . .
	. . . . . . .
	. . X . X . .
	. . . P . . .
	. . . . . . .
	. . . . . . .
	. . . . . . .

Fou / Bishop (B):

	X . . . . . X
	. X . . . X .
	. . X . X . .
	. . . B . . .
	. . X . X . .
	. X . . . X .
	X . . . . . X

Tour / Rook (R):

	. . . X . . .
	. . . X . . .
	. . . X . . .
	X X X R X X X
	. . . X . . .
	. . . X . . .
	. . . X . . .

Dame / Queen (Q)

	X . . X . . X
	. X . X . X .
	. . X X X . .
	X X X Q X X X
	. . X X X . .
	. X . X . X .
	X . . X . . X 


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>
#include <unistd.h>

int		check_mate(int ac, char **av)
{
	int		y = 0;
	int		x = 0;
	int		len = 0;
	int		b = 0;
	int		a = 0;
	char	**m;
	int		i = 0;

	while (ac-- > 1)
		len++;
	if (!(m = (char **)malloc(sizeof(char *) * len * (len + 1))))
		return (0);
	y = 0;
	while (y < len)
	{
		if (!(m[y] = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		x = 0;
		while (av[y + 1][x])
		{
			m[y][x] = av[y + 1][x];
			if (m[y][x] == 'K')
			{
				a = x;
				b = y;
			}
			++x;
		}
		m[y][x] = 0;
		++y;
	}

	if (m[b + 1][a + 1] == 'P' || m[b + 1][a - 1] == 'P')
		return (0);
	while (i < len)
	{
		if (m[b][i] == 'Q' || m[i][a] == 'Q' || m[b][i] == 'R' || m[i][a] == 'R')
			return (0);
		if (i < b)
		{
			if (i < a && (m[b - i - 1][a - i - 1] == 'B' || m[b - i - 1][a - i - 1] == 'Q') )
				return (0);
			if (a + i < len && (m[b - i - 1][a + i + 1] == 'B' || m[b - i - 1][a + i + 1] == 'Q'))
				return (0);
		}
		if (b + i < len)
		{
			if (i < a && (m[b + i + 1] [a - i - 1] == 'B' || m[b + i + 1] [a - i - 1] == 'Q'))
				return (0);
			if (a + i < len && (m[b + i + 1] [a + i + 1] == 'B' || m[b + i + 1] [a + i + 1] == 'Q' ))
				return (0);
		}
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (ac > 1 && check_mate(ac, av))
		write(1, "Success\n", 8);
	else
		write(1, "Fail\n", 5);
	return (0);
}


/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */



#include <stdlib.h>
#include <unistd.h>

// gcc checkmate.c && ./a.out '..R.' '.Q..' '..BK' '...P' | cat -e
// B = 3      Rook = 2 and Queen == 6   an P == 1

int		checkmate(int ac, char **av)
{
	int		y = 0;
	int		x = 0;
	int		len = 0;
	int		b = 0;
	int		a = 0;
	char	**m;

	// creating map
	while (ac-- > 1)
		len++;
	if (!(m = (char **)malloc(sizeof(char *) * len * (len + 1))))
		return (0);
	y = 0;
	while (y < len)
	{
		if (!(m[y] = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		x = 0;
		while (av[y + 1][x])
		{
			m[y][x] = av[y + 1][x];
			if (m[y][x] == 'K')
			{
				a = x;
				b = y;
			}
			++x;
		}
		m[y][x] = 0;
		++y;
	}

	// checking if the King is endangered by a pawn
	if (m[b + 1][a + 1] == 'P' || m[b + 1][a - 1] == 'P')
		return (0);

	int		i = 0;
	while (i < len)
	{
		if (m[b][i] == 'Q' || m[i][a] == 'Q' || m[b][i] == 'R' || m[i][a] == 'R')
			return (0);
		if (i < b)
		{
			if (i < a && (m[b - i - 1][a - i - 1] == 'B' || m[b - i - 1][a - i - 1] == 'Q') )
				return (0);
			if (a + i < len && (m[b - i - 1][a + i + 1] == 'B' || m[b - i - 1][a + i + 1] == 'Q'))
				return (0);
		}
		if (b + i < len)
		{
			if (i < a && (m[b + i + 1] [a - i - 1] == 'B' || m[b + i + 1] [a - i - 1] == 'Q'))
				return (0);
			if (a + i < len && (m[b + i + 1] [a + i + 1] == 'B' || m[b + i + 1] [a + i + 1] == 'Q' ))
				return (0);
		}
		i++;
	}
	return (1);
}


void	print(int ac, char **av)
{	
	int		len;
	int		x;
	int		y;
	char	**m;

	// creating map
	while (ac-- > 1)
		len++;
	if (m = (char **)malloc(sizeof(char *) * len * (len + 1)))
	{
		y = 0;
		while (y < len)
		{
			if (!(m[y] = (char *)malloc(sizeof(char) * (len + 1))))
				return ;
			x = 0;
			while (av[y + 1][x])
			{
				m[y][x] = av[y + 1][x];
				++x;
			}
			m[y][x] = 0;
			++y;
		}
		// printing map
		y = 0;
		while (y < len)
		{
			write(1, m[y++], len);
			write(1, "\n", 1);
		}
	}
}


int		main(int ac, char **av)
{
	if (ac > 1 && checkmate(ac, av))
		write(1, "Success\n", 8);
	else
		write(1, "Fail\n", 5);
	print(ac, av);
	return (0);
}