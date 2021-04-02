/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 15:22:24 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/03/10 01:23:33 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/bsq.h"

t_uns		prepare_read(int fd)
{
	char	buffer;
	t_grid	grid = {0};
	t_coord	xy = {0, 1, (void *)0};

	if (!(ft_read(fd, &buffer, &grid, &xy)))
		return (0);
	return (1);
}

t_uns		first_line(char *buffer, t_grid *grid)
{
	char swap;

	swap = grid->char_empty;
	if (!((swap >= '0' && swap <= '9') || swap == 0))
		return (0);
	grid->char_empty = grid->char_mine;
	grid->char_mine = grid->char_square;
	grid->char_square = *buffer;
	if (swap != 0)
		grid->y = (grid->y * 10) + (swap - '0');
	return (1);
}

t_uns		ft_read(int fd, char *buffer, t_grid *grid, t_coord *xy)
{
	char		first;
	t_coord		**begin;
	t_coord		*tmp;

	first = 1;
	tmp = 0;
	begin = &tmp;
	while (read(fd, buffer, 1))
	{
		if (*buffer == '\n' && first == 1)
			first = 0;
		else if (first == 1)
		{
			if (!(first_line(buffer, grid)))
				return (0);
		}
		else if (!(ft_read_char(xy, buffer, grid, begin)))
			return (0);
	}
	return (ft_after_read(xy, grid, begin));
}

t_uns		ft_read_char(t_coord *xy, char *buffer, t_grid *grid,
							t_coord **begin)
{
	xy->x++;
	if (*buffer == grid->char_mine)
		push_back(begin, xy);
	else if (*buffer == '\n')
	{
		if (grid->x == 0)
			grid->x = xy->x;
		if (grid->x != xy->x)
			return (0);
		xy->x = 0;
		xy->y++;
	}
	else if (*buffer != grid->char_empty)
		return (0);
	return (1);
}

t_uns		ft_after_read(t_coord *xy, t_grid *grid, t_coord **begin)
{
	t_square	*square;
	t_coord		*copy;

	copy = *begin;
	if (grid->char_empty == grid->char_mine ||
		grid->char_empty == grid->char_square ||
		grid->char_mine == grid->char_square)
		return (0);
	if (xy->y - 1 != grid->y)
		return (0);
	grid->x = grid->x - 1;
	square = algo_bsq(&copy, grid);
	grid->x = grid->x + 1;
	display(square, grid, begin);
	return (1);
}
