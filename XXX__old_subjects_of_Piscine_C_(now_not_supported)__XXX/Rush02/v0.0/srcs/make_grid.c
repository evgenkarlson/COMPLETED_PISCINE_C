/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 16:25:37 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/28 22:17:01 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		get_x(char *str)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i] != '\n')
	{
		if (str[i++] == '\0')
			return (-1);
		x++;
	}
	return (x);
}

int		get_y(char *str)
{
	int y;
	int i;

	i = 0;
	y = 0;
	while (str[i] != '\0')
		if (str[i++] == '\n')
			y++;
	return (y);
}

void	copy_grid(char **grid, char *str, int x, int y)
{
	int i;
	int a;
	int b;

	i = 0;
	b = 0;
	while (b < y)
	{
		a = 0;
		while (a < x)
			grid[b][a++] = str[i++];
		i++;
		b++;
	}
}

char	**make_space(char **grid, int x, int y)
{
	int i;

	i = 0;
	grid = (char**)malloc(sizeof(char*) * y);
	while (i < y)
		grid[i++] = (char*)malloc(sizeof(char) * x);
	return (grid);
}
