/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_colle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 15:43:36 by adespond          #+#    #+#             */
/*   Updated: 2015/09/20 17:36:46 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colle.h"

char	*generate_line(int x, char *colle, char *pattern, int line)
{
	int ix;

	ix = 0;
	while (ix < x)
	{
		if (ix == 0)
			*colle = pattern[line];
		else if ((ix + 1) == x)
			*colle = pattern[line + 2];
		else
			*colle = pattern[line + 1];
		colle++;
		ix++;
	}
	*colle = '\n';
	colle++;
	return (colle);
}

char	*generate_colle(int x, int y, char *pattern)
{
	char	*colle;
	char	*colle_begin;
	int		iy;
	int		line;

	iy = 0;
	colle = (char *)malloc(sizeof(char) * (x + 1) * y);
	colle_begin = colle;
	while (iy < y)
	{
		if (iy == 0)
			line = 0;
		else if ((iy + 1) == y)
			line = 6;
		else
			line = 3;
		colle = generate_line(x, colle, pattern, line);
		iy++;
	}
	return (colle_begin);
}
