/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r03c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 13:48:16 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/28 14:58:53 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	get_corner_03(int x)
{
	if (x == 0)
		return ('A');
	else
		return ('C');
}

int		r03c(int w, int l, char **input_array)
{
	int	x;
	int y;

	y = -1;
	while (++y < l)
	{
		x = -1;
		while (++x < w)
		{
			if (num_sides(x, y, w, l) == 2)
			{
				if (get_corner_03(x) != input_array[y][x])
					return (0);
			}
			else if (num_sides(x, y, w, l) == 1)
			{
				if (input_array[y][x] != 'B')
					return (0);
			}
			else if (input_array[y][x] != ' ')
				return (0);
		}
	}
	return (1);
}
