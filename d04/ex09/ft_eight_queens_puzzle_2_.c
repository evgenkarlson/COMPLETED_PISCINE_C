/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 - Écrire une fonction qui affiche toutes les possibilités de placer les huit dames sur l’échiquier sans qu’elles ne puissent s’atteindre.
 - La recursivité devra être utilisée.

 - La suite se lit de gauche à droite. Le premier chiffre correspond à la position de la première dame dans la première colonne (l(index commena̧nt à 1). Le énième chiffre correspond à la position de la énième dame dans la énième colonne.
 - Il y a un saut de ligne après la dernière solution.
 -  Votre fonction doit donner son résultat en moins de deux secondes.
*/
/* ************************************************************************** */
/*
 - Напишите функцию, которая отображает все возможности размещения восьми женщин на 
   шахматной доске, не позволяя им достичь друг друга.
 - Рекурсивность должна быть использована.

 - Комплект можно прочитать слева направо. Первая цифра соответствует положению 
   первой леди в первом столбце (l (индекс начинается с 1). Самая высокая цифра 
   соответствует положению первой леди в столбце десятого.
 - После последнего решения есть разрыв строки.
 - Ваша функция должна дать свой результат менее чем за две секунды.
*/
/* ************************************************************************** */


#define ABS(a, b)	((a >= b) ? (a - b) : (b - a))

int			ft_putchar(char c);

static void	solve_queens_puzzle(int queens, int col, int *board)
{
	int		i;
	int		j;

	if (col == queens)
	{
		i = -1;
		while (++i < queens)
		{
			j = 0;
			while (j < queens)
				(j++ == board[i]) ? ft_putchar(j + '0') : 0;
		}
		ft_putchar('\n');
	}
	i = 0;
	while (i < queens)
	{
		j = 0;
		while (j < col && !(board[j] == i || ABS(board[j], i) == col - j))
			j += 1;
		if (j < col && i++ < queens)
			continue ;
		board[col] = i++;
		solve_queens_puzzle(queens, col + 1, board);
	}
}

void		ft_eight_queens_puzzle_2(void)
{
	int		board[8];
	int		queens;
	int		pos;

	queens = 8;
	pos = 0;
	solve_queens_puzzle(queens, pos, board);
}
