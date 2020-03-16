/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_rush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 15:02:30 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/23 15:02:31 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_rect.h"
#include "str.h"
#include "io.h"

t_rect	get_rekt(char **data)
{
	t_rect	r;
	int		len;

	r.w = 0;
	r.h = 0;
	while (data[r.h])
	{
		len = ft_strlen(data[r.h]);
		r.h++;
		if (!r.w)
			r.w = len;
		else if (r.w != len)
		{
			r.h = 0;
			r.w = 0;
			return (r);
		}
	}
	return (r);
}

int		match_rush_corners(char **data, t_rect r, char *sig)
{
	return (!(data[0][0] != sig[0] ||
		(data[0][r.w - 1] != sig[1] && r.w > 1) ||
		(data[r.h - 1][0] != sig[2] && r.h > 1) ||
		(data[r.h - 1][r.w - 1] != sig[3] && r.w > 1 && r.h > 1)));
}

int		match_rush(char **data, t_rect r, char *sig)
{
	int i;
	int j;

	if (!match_rush_corners(data, r, sig))
		return (0);
	i = 0;
	while (i < r.h)
	{
		j = 0;
		while (j < r.w)
		{
			if (i > 0 && i < r.h - 1 && (j == 0 || j == r.w - 1))
				if (data[i][j] != sig[5])
					return (0);
			if (j > 0 && j < r.w - 1 && (i == 0 || i == r.h - 1))
				if (data[i][j] != sig[4])
					return (0);
			if (i > 0 && i < r.h - 1 && j > 0 && j < r.w - 1)
				if (data[i][j] != ' ')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	display(char *str, int a, int b, int *is_first)
{
	if (*is_first)
		*is_first = 0;
	else
		ft_putstr(" || ");
	ft_putchar('[');
	ft_putstr(str);
	ft_putstr("] [");
	ft_putnbr(a);
	ft_putstr("] [");
	ft_putnbr(b);
	ft_putchar(']');
}

void	match_shape(char **data)
{
	t_rect	r;
	int		first;

	first = 1;
	r = get_rekt(data);
	if (r.w && r.h)
	{
		if (match_rush(data, r, "oooo-|"))
			display("colle-00", r.w, r.h, &first);
		if (match_rush(data, r, "/\\\\/**"))
			display("colle-01", r.w, r.h, &first);
		if (match_rush(data, r, "AACCBB"))
			display("colle-02", r.w, r.h, &first);
		if (match_rush(data, r, "ACACBB"))
			display("colle-03", r.w, r.h, &first);
		if (match_rush(data, r, "ACCABB"))
			display("colle-04", r.w, r.h, &first);
	}
	if (first)
		ft_putstr("aucune");
	ft_putchar('\n');
}
