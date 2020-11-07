/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r01c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 14:15:11 by jaleman           #+#    #+#             */
/*   Updated: 2016/08/28 14:59:09 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	get_corner_01(int a, int b, int width, int length)
{
	if ((a == b) || ((a == (width - 1)) && (b == (length - 1))))
		return ('/');
	return ('\\');
}

int		r01c(int width, int length, char **input)
{
	int		x;
	int		y;

	y = -1;
	while (++y < length)
	{
		x = -1;
		while (++x < width)
		{
			if (num_sides(x, y, width, length) == 2)
			{
				if (get_corner_01(x, y, width, length) != input[y][x])
					return (0);
			}
			else if (num_sides(x, y, width, length) == 1)
			{
				if (input[y][x] != '*')
					return (0);
			}
			else if (input[y][x] != ' ')
				return (0);
		}
	}
	return (1);
}
