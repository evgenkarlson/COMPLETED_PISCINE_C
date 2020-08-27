/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 - Le but de ce jeu est de placer huit dames sur un échiquier sans qu’elles ne puissent s’atteindre en un seul coup.
 - Rafraîchissez-vous la mémoire sur les règles des échecs.
 - Bien entendu, on utilisera la recursivité pour résoudre ce problème.
 - Écrire une fonction qui renvoie le nombre de possibilités de placer les huit dames sur l’échiquier sans qu’elles ne puissent s’atteindre.
*/
/* ************************************************************************** */
/*
 - Цель этой игры - разместить на шахматной доске восемь шашек, чтобы они не могли
   достичь друг друга одним махом.
 - освежить память о правилах шахмат.
 - Конечно, мы будем использовать рекурсивность для решения этой проблемы.
 - Напишите функцию, которая возвращает количество возможностей разместить восемь 
   женщин на шахматной доске, не имея возможности связаться друг с другом.


** ************************************************************************** **

 	P.S в этом задании вас просят найти все возможные варианты размещения фигур
	согласно условию!

* ************************************************************************** */

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


/* ************************************************************************** */
