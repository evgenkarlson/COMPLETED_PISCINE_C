/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:14:30 by cromalde          #+#    #+#             */
/*   Updated: 2021/08/08 21:12:50 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_col_up(int board[4][4], int col, int num)
{
	int i;
	int max;
	int count;

	i = 0;
	count = 1;
	max = board[i][col];
	while (i < 4)
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			count++;
		}
		i++;
	}
	if (count == num)
		return (1);
	return (0);
}

int		check_col_down(int board[4][4], int col, int num)
{
	int i;
	int max;
	int count;

	i = 3;
	count = 1;
	max = board[i][col];
	while (i >= 0)
	{
		if (board[i][col] > max)
		{
			max = board[i][col];
			count++;
		}
		i--;
	}
	if (count == num)
		return (1);
	return (0);
}

int		check_row_left(int board[4][4], int row, int num)
{
	int i;
	int max;
	int count;

	i = 0;
	count = 1;
	max = board[row][i];
	while (i < 4)
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			count++;
		}
		i++;
	}
	if (count == num)
		return (1);
	return (0);
}

int		check_row_right(int board[4][4], int row, int num)
{
	int i;
	int max;
	int count;

	i = 3;
	count = 1;
	max = board[row][i];
	while (i >= 0)
	{
		if (board[row][i] > max)
		{
			max = board[row][i];
			count++;
		}
		i--;
	}
	if (count == num)
		return (1);
	return (0);
}

int		checkboard(int board[4][4], int *in_num)
{
	int i;

	i = 0;
	while (in_num[i])
	{
		if (i >= 0 && i <= 3)
			if (!check_col_up(board, i, in_num[i]))
				return (0);
		if (i >= 4 && i <= 7)
			if (!check_col_down(board, i - 4, in_num[i]))
				return (0);
		if (i >= 8 && i <= 11)
			if (!check_row_left(board, i - 8, in_num[i]))
				return (0);
		if (i >= 12 && i <= 15)
			if (!check_row_right(board, i - 12, in_num[i]))
				return (0);
		i++;
	}
	return (1);
}
