/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:11:30 by etaranti          #+#    #+#             */
/*   Updated: 2020/11/12 12:05:29 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

void	ft_free(void)
{
	int i;

	i = 0;
	while (i < g_row)
	{
		free(g_board[i]);
		i++;
	}
	free(g_board);
}

void	ft_printboard(int len)
{
	int i;
	int j;

	i = 0;
	while (i < g_row)
	{
		j = 0;
		while (j < len)
		{
			if (g_board[i][j] == 0)
				ft_putchar(g_obst);
			else if (g_board[i][j] == g_full)
				ft_putchar(g_full);
			else
				ft_putchar(g_empty);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_free();
}
