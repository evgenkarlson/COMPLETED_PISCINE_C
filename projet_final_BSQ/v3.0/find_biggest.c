/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkinzel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 00:08:37 by lkinzel           #+#    #+#             */
/*   Updated: 2017/07/26 23:09:10 by lkinzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	checkfirstrow(int **arr)
{
	int con;
	int foundfirst;
	int	startingpos[2];

	foundfirst = 0;
	startingpos[0] = 0;
	startingpos[1] = 0;
	while (startingpos[1] + g_dim < g_length)
	{
		con = 1;
		while (con)
		{
			if (brute_force_valid(arr, startingpos, g_dim + foundfirst))
			{
				if (foundfirst)
					g_dim++;
				g_pos[0] = 0;
				g_pos[1] = startingpos[1];
				foundfirst = 1;
			}
			else
				con = 0;
		}
		startingpos[1]++;
	}
}

void	checkfirstcol(int **arr, int con, int onthisrow, int foundfirst)
{
	int startingpos[2];

	startingpos[0] = 1;
	startingpos[1] = 0;
	while (startingpos[0] + g_dim < g_length)
	{
		con = 1;
		while (con)
		{
			onthisrow = 1;
			if ((g_pos[0] == startingpos[0]) && (!foundfirst))
				onthisrow = 0;
			if (brute_force_valid(arr, startingpos, g_dim + onthisrow))
			{
				if (onthisrow)
					g_dim++;
				g_pos[0] = startingpos[0];
				g_pos[1] = startingpos[1];
				foundfirst = 1;
			}
			else
				con = 0;
		}
		startingpos[0]++;
	}
}

void	checkmain(int **arr, int con)
{
	int	startingpos[2];

	startingpos[0] = 1;
	startingpos[1] = 1;
	while (startingpos[0] + g_dim < g_height)
	{
		startingpos[1] = 1;
		while (startingpos[1] + g_dim < g_length)
		{
			con = 1;
			while (con)
			{
				if (is_valid(arr, startingpos, g_dim + 1))
				{
					g_dim++;
					g_pos[0] = startingpos[0];
					g_pos[1] = startingpos[1];
				}
				else
					con = 0;
			}
			startingpos[1]++;
		}
		startingpos[0]++;
	}
}

void	find_biggest(int **arr, char *str_no_information)
{
	int **tab;

	g_pos[0] = 0;
	g_pos[1] = 0;
	g_dim = 0;
	checkmain(arr, 1);
	make_it_numbers(&tab, str_no_information, g_height, 0);
	checkfirstrow(tab);
	checkfirstcol(tab, 1, 0, 0);
}
