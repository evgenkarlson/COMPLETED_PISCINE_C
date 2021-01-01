/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 09:22:41 by etaranti          #+#    #+#             */
/*   Updated: 2020/11/12 12:05:37 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq_lib.h"

int		ft_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strerror(void)
{
	write(2, "map error", 9);
	write(2, "\n", 1);
	return (-1);
}

void	ft_spcase(int *max, int col)
{
	int i;

	i = 0;
	while (i < col)
	{
		if (g_board[0][i] == 1)
		{
			max[0] = 1;
			max[1] = 0;
			max[2] = i;
			return ;
		}
		i++;
	}
	i = -1;
	while (++i < g_row)
	{
		if (g_board[i][0] == 1)
		{
			max[0] = 1;
			max[1] = i;
			max[2] = 0;
		}
	}
}
