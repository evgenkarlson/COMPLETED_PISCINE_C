/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/27 19:26:53 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/28 23:16:24 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

int		empty_input(char *str)
{
	if (*str == '\0')
	{
		return (1);
	}
	return (0);
}

void	disp_results(int x, int y, char **grid, int num_rushes)
{
	int		index;
	int		xy[2];

	if (num_rushes == 0)
	{
		ft_putstr("Noid\n");
		return ;
	}
	index = 0;
	xy[0] = x;
	xy[1] = y;
	if (r00c(x, y, grid))
		print_rush("rush-00", xy, ++index, num_rushes);
	if (r01c(x, y, grid))
		print_rush("rush-01", xy, ++index, num_rushes);
	if (r02c(x, y, grid))
		print_rush("rush-02", xy, ++index, num_rushes);
	if (r03c(x, y, grid))
		print_rush("rush-03", xy, ++index, num_rushes);
	if (r04c(x, y, grid))
		print_rush("rush-04", xy, ++index, num_rushes);
	ft_putchar('\n');
}

int		get_num_of_solutions(int x, int y, char **grid)
{
	int		num_rushes;

	num_rushes = 0;
	if (r00c(x, y, grid))
		num_rushes++;
	if (r01c(x, y, grid))
		num_rushes++;
	if (r02c(x, y, grid))
		num_rushes++;
	if (r03c(x, y, grid))
		num_rushes++;
	if (r04c(x, y, grid))
		num_rushes++;
	return (num_rushes);
}

char	**helper(int *x, int *y, char **grid)
{
	char	*str;

	str = ft_import_stdin();
	if (empty_input(str))
	{
		*x = 0;
		*y = 0;
	}
	else
	{
		*x = get_x(str);
		if (*x < 0)
			return (grid);
		*y = get_y(str);
	}
	grid = make_space(grid, *x, *y);
	copy_grid(grid, str, *x, *y);
	return (grid);
}

int		main(void)
{
	int		x;
	int		y;
	char	**grid;
	int		num_rushes;

	grid = helper(&x, &y, grid);
	if (x >= 0)
	{
		num_rushes = get_num_of_solutions(x, y, grid);
		disp_results(x, y, grid, num_rushes);
	}
	else
		ft_putstr("Noid\n");
	return (0);
}
