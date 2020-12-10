/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:11:15 by etaranti          #+#    #+#             */
/*   Updated: 2020/11/12 12:05:51 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

void	ft_case1(void)
{
	if (g_board[0][0] == g_empty)
	{
		write(1, &g_full, 2);
		write(1, "\n", 1);
		exit(0);
	}
	if (g_board[0][0] == g_obst)
	{
		write(1, &g_obst, 1);
		write(1, "\n", 1);
		exit(0);
	}
}

int		ft_setok(void)
{
	if ((g_row < 1) || (g_full < 0 || g_full > 126) || (g_obst < 0 ||
			g_obst > 126) || (g_empty < 0 || g_empty > 126) ||
			(g_obst == g_empty) || (g_full == g_empty || g_full == g_obst))
	{
		ft_strerror();
		return (0);
	}
	return (1);
}

int		ft_charsafe(char c, int *col, int len, int *r)
{
	if ((c == g_empty) && (*col <= len))
		g_board[*r][*col] = (1);
	if ((c == g_obst) && (*col <= len))
		g_board[*r][*col] = (0);
	if (!(c == g_empty) && !(c == g_obst))
		return (-1);
	return (1);
}

int		ft_checklen(int *j, int len, int *i)
{
	if (*j != len)
		return (-1);
	*j = 0;
	(*i)++;
	return (0);
}
