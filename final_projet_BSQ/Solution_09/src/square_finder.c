/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-thie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 11:50:44 by ple-thie          #+#    #+#             */
/*   Updated: 2018/07/25 22:00:50 by pforciol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		ft_calculate_point(int **map, int line, int col)
{
	int min;

	if (line == 0 || col == 0)
		return (1);
	min = map[line - 1][col];
	if (map[line][col - 1] < min)
		min = map[line][col - 1];
	if (map[line - 1][col - 1] < min)
		min = map[line - 1][col - 1];
	return (min + 1);
}

void	ft_square_find(int **map, t_map_loc *best_loc)
{
	int i;
	int j;

	i = best_loc->y;
	while (i > best_loc->y - best_loc->point)
	{
		j = best_loc->x;
		while (j > best_loc->x - best_loc->point)
		{
			map[i][j] = -1;
			j--;
		}
		i--;
	}
}

int		**ft_square_calc(int **map, t_map_params map_params)
{
	int			i;
	int			j;
	t_map_loc	best_loc;

	best_loc.point = -1;
	i = -1;
	while (++i < map_params.lines)
	{
		j = -1;
		while (++j < map_params.columns - 1)
		{
			if (map[i][j] == -1)
			{
				map[i][j] = ft_calculate_point(map, i, j);
				if (map[i][j] > best_loc.point)
				{
					best_loc.x = j;
					best_loc.y = i;
					best_loc.point = map[i][j];
				}
			}
		}
	}
	ft_square_find(map, &best_loc);
	return (map);
}
