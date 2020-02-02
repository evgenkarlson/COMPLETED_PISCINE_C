/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpucelle <jpucelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/21 23:36:44 by jpucelle          #+#    #+#             */
/*   Updated: 2014/07/23 12:12:11 by jpucelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_square.h"

int		calc_columns(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

int		calc_size(t_bsq a, t_obj b, int k, int l)
{
	int i;
	int j;
	int size;

	size = 1;
	while (a.map[k] == b.empty && a.map[l] == b.empty)
	{
		i = k;
		j = l;
		while (a.map[k] == b.empty && a.map[l] == b.empty && k < l)
		{
			k += a.columns + 1;
			l++;
			if (a.map[k] == b.obstacle || a.map[l] == b.obstacle)
				return (size);
		}
		k = i + 1;
		l = j + a.columns + 1;
		size++;
	}
	return (size);
}

char	*draw_square(t_bsq a, t_obj b)
{
	int i;
	int j;
	int k;
	int l;

	j = 0;
	k = a.position;
	l = k + a.size;
	i = 1;
	while (j < a.size)
	{
		while (k < l)
		{
			a.map[k] = b.wall;
			k++;
		}
		k = a.position + ((a.columns + 1) * i);
		l = k + a.size;
		i++;
		j++;
	}
	return (a.map);
}

char	*calc_square(t_bsq a, t_obj b)
{
	int i;
	int k;
	int l;
	int size;

	i = 0;
	size = 0;
	while (a.map[i] != '\0')
	{
		if (a.map[i] == b.empty)
		{
			k = i + 1;
			l = i + a.columns + 1;
			size = calc_size(a, b, k, l);
			if (a.size < size)
			{
				a.position = i;
				a.size = size;
			}
		}
		i++;
	}
	return (draw_square(a, b));
}

int		bsq(char *map)
{
	t_bsq	a;
	t_obj	b;

	jp_putstr("test");
	a.map = map;
	a.columns = calc_columns(map);
	a.position = 0;
	a.size = 0;
	b.empty = '.';
	b.obstacle = 'o';
	b.wall = 'x';
	jp_putstr(calc_square(a, b));
	return (1);
}
