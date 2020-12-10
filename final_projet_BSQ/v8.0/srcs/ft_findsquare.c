/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findsquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:11:00 by etaranti          #+#    #+#             */
/*   Updated: 2020/11/12 09:52:45 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int		ft_checkmax(int *r, int *c)
{
	int r_1;
	int c_1;
	int rc_1;
	int min;

	r_1 = g_board[*r - 1][*c];
	c_1 = g_board[*r][*c - 1];
	rc_1 = g_board[*r - 1][*c - 1];
	if (r_1 <= c_1)
		min = r_1;
	else
		min = c_1;
	if (min >= rc_1)
		min = rc_1;
	return (min);
}

void	ft_resolve(int *max, int col)
{
	int c;
	int r;

	c = 0;
	while (c < (max[0]))
	{
		r = 0;
		while (r < (max[0]))
		{
			g_board[max[1] - r][max[2] - c] = g_full;
			r++;
		}
		c++;
	}
	ft_printboard(col);
}

void	ft_findmax(int *r, int *c, int min, int *max)
{
	if (max[0] < min)
	{
		max[0] = min;
		max[1] = *r;
		max[2] = *c;
	}
}

void	ft_findsquare(int col)
{
	int r;
	int c;
	int min;
	int max[3];

	r = 1;
	min = 0;
	max[0] = 0;
	while (r < g_row)
	{
		c = 1;
		while (c < col)
		{
			if (g_board[r][c] == 1)
			{
				min = ft_checkmax(&r, &c);
				g_board[r][c] = min + 1;
				ft_findmax(&r, &c, (min + 1), max);
			}
			c++;
		}
		r++;
	}
	(max[0] <= 1) ? ft_spcase(max, col) : min++;
	ft_resolve(max, col);
}
